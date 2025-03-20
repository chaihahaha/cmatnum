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

[6] Drevet, Charles-Éric et al. “Optimization techniques for small matrix multiplication.” Theor. Comput. Sci. 412 (2011): 2219-2236.

[7] Respondek, J. S. (2025). Fast matrix multiplication with applications. doi:10.1007/978-3-031-76930-6

[8] Smirnov, A.V. (2013). The bilinear complexity and practical algorithms for matrix multiplication. Computational Mathematics and Mathematical Physics, 53, 1781-1795.
