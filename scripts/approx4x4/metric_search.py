#!/usr/bin/env python3
"""Optimise a rank-R approximate <4,4,4> algorithm for the *metric that
src/benchmark.c actually measures*:

    err(A,B) = max|C_alg - A*B| / max|A*B|          (A,B uniform on [-1,1])

The Frobenius tensor error used by the CP search is only a proxy: for the
matrix-multiplication tensor ||T||_F / ||T||_inj = 8, i.e. the Frobenius norm can
overestimate the error that a max-type metric sees by up to an order of
magnitude.  Here the metric itself is minimised by stochastic gradient descent
on freshly sampled inputs, starting from a CP solution.
"""

from __future__ import annotations

import argparse
import os
import sys
import time

import numpy as np
import torch

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from tensor_utils import cp_tensor, matmul_tensor  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(HERE))


def metric(a, b, c, n=4, trials=200, seed=0, device="cpu", dtype=torch.float64):
    """Evaluate err = max|C_alg - C| / max|C| on fresh uniform inputs."""
    g = torch.Generator(device="cpu").manual_seed(seed)
    A = (torch.rand(trials, n * n, generator=g, dtype=torch.float64) * 2 - 1)
    B = (torch.rand(trials, n * n, generator=g, dtype=torch.float64) * 2 - 1)
    with torch.no_grad():
        C = (A.view(-1, n, n) @ B.view(-1, n, n)).view(-1, n * n)
        m = (a.to(dtype) @ A.T) * (b.to(dtype) @ B.T)
        Ch = c.to(dtype).T @ m
        diff = (Ch - C.T).abs().amax(dim=0)
        scale = C.abs().amax(dim=1).clamp_min(1e-12)
        return float((diff / scale).max()), float((diff / scale).mean())


def train(a0, b0, c0, steps=4000, batch=512, lr=3e-3, seed=0, verbose=True,
          huber=0.0, n=4):
    torch.manual_seed(seed)
    a = torch.tensor(a0, dtype=torch.float64, requires_grad=True)
    b = torch.tensor(b0, dtype=torch.float64, requires_grad=True)
    c = torch.tensor(c0, dtype=torch.float64, requires_grad=True)
    opt = torch.optim.Adam([a, b, c], lr=lr)
    sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, steps, eta_min=lr * 0.02)
    g = torch.Generator().manual_seed(seed + 1)
    best = (np.inf, a0.copy(), b0.copy(), c0.copy())
    for it in range(steps):
        A = torch.rand(batch, n * n, generator=g, dtype=torch.float64) * 2 - 1
        B = torch.rand(batch, n * n, generator=g, dtype=torch.float64) * 2 - 1
        C = (A.view(-1, n, n) @ B.view(-1, n, n)).view(-1, n * n)
        m = (a @ A.T) * (b @ B.T)
        Ch = c.T @ m
        diff = (Ch - C.T).abs()
        scale = C.abs().amax(dim=1).clamp_min(1e-12)
        r = diff / scale[None, :]
        if huber > 0:
            loss = torch.where(r < huber, 0.5 * r * r / huber, r - 0.5 * huber).mean()
        else:
            loss = r.mean()
        opt.zero_grad(); loss.backward(); opt.step(); sched.step()
        if it % 250 == 249 or it == steps - 1:
            mx, mn = metric(a, b, c, n=n, seed=999)
            if mx < best[0]:
                best = (mx, a.detach().numpy().copy(), b.detach().numpy().copy(),
                        c.detach().numpy().copy())
            if verbose:
                print(f"  step {it+1:5d}  train={float(loss):.4e}  "
                      f"val max={mx:.4e} mean={mn:.4e}", flush=True)
    return best


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("npz")
    ap.add_argument("--name", required=True)
    ap.add_argument("--steps", type=int, default=4000)
    ap.add_argument("--batch", type=int, default=512)
    ap.add_argument("--lr", type=float, default=3e-3)
    ap.add_argument("--huber", type=float, default=0.0)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=os.path.join(ROOT, "results", "approx4x4", "metric"))
    args = ap.parse_args()
    os.makedirs(args.out, exist_ok=True)
    d = np.load(args.npz)
    a0, b0, c0 = d["a"], d["b"], d["c"]
    R = a0.shape[0]
    T = matmul_tensor(4)
    print(f"start rank {R}: tensor_rel={np.linalg.norm(T-cp_tensor(a0,b0,c0))/np.linalg.norm(T):.4e} "
          f"metric={metric(torch.tensor(a0), torch.tensor(b0), torch.tensor(c0))[0]:.4e}", flush=True)
    t0 = time.time()
    mx, a, b, c = train(a0, b0, c0, args.steps, args.batch, args.lr, args.seed,
                        huber=args.huber)
    print(f"rank {R}: best val max-metric = {mx:.4e}  ({time.time()-t0:.0f}s)", flush=True)
    rel = float(np.linalg.norm(T - cp_tensor(a, b, c)) / np.linalg.norm(T))
    print(f"  tensor rel err now {rel:.4e}", flush=True)
    np.savez(os.path.join(args.out, f"metric_4x4_{args.name}.npz"),
             a=a, b=b, c=c, rel_error=rel, metric=mx)


if __name__ == "__main__":
    main()
