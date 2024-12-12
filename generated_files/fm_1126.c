#include "stdafx.h"
#include "fm_1126.h"

inline int fm_1126(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1797, bmats.Axx2345, bmats.Axx521, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.Bx9318, bmats.Bx9925, bmats.Bx9946, bmats.Bx9947, bmats.Bx9948, bmats.Bx9949, bmats.Bx9950, bmats.Bx9951, bmats.Bx9952, bmats.Bx9953, bmats.Bx9954, bmats.Bx9955, };
    double B_coeffs[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_21_8.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
