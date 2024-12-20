# cmatnum
my C language math and numerical computing library

## Build
```
mkdir build
cd build
cmake .. -DBLAS_openblas_LIBRARY=/path/to/lib/libopenblas.so.0
cmake --build .
```

## References

[1] Karstadt, Elaye and Oded Schwartz. “Matrix Multiplication, a Little Faster.” Journal of the ACM (JACM) 67 (2020): 1 - 31.

[2] Benson, Austin R. and Grey Ballard. “A framework for practical parallel fast matrix multiplication.” Proceedings of the 20th ACM SIGPLAN Symposium on Principles and Practice of Parallel Programming (2014): n. pag.

[3] Schwartz, Oded et al. “Alternative Basis Matrix Multiplication is Fast and Stable.” 2024 IEEE International Parallel and Distributed Processing Symposium (IPDPS) (2024): 38-51.

[4] https://github.com/arbenson/fast-matmul

[5] https://fmm.univ-lille.fr
