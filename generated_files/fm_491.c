#include "stdafx.h"
#include "fm_491.h"

inline int fm_491(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1043, bmats.Axx1494, bmats.Axx2438, };
    double A_coeffs[3] = {-1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_4_29, bmats.Bx3180, bmats.Bx4084, bmats.Bx4085, bmats.Bx4086, bmats.Bx4087, bmats.Bx4088, bmats.Bx4089, bmats.Bx4090, bmats.Bx4091, bmats.Bx4092, bmats.Bx4093, bmats.Bx4094, bmats.Bx4095, bmats.Bx4096, bmats.Bx4097, bmats.Bx4099, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_20_29.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
