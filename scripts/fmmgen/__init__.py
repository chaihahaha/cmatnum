"""Unified code generator for recursive fast matrix-multiplication algorithms."""

from .algorithm import Algorithm, load_algorithm, load_from_triadset, load_from_txt, save_as_txt
from .codegen import Options, Program, build_program, emit
from .schedule import peak_memory

__all__ = [
    "Algorithm",
    "load_algorithm",
    "load_from_triadset",
    "load_from_txt",
    "save_as_txt",
    "Options",
    "Program",
    "build_program",
    "emit",
    "peak_memory",
]
