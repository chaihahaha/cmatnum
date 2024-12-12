#include "stdafx.h"
#include "fm_990.h"

inline int fm_990(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx3295, bmats.Axx533, bmats.Axx578, bmats.Axx604, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_3_14, bmats.B_3_7, bmats.B_3_9, bmats.B_5_9, bmats.B_7_9, bmats.B_9_9, bmats.Bx4978, bmats.Bx8350, bmats.Bx8996, bmats.Bx8997, bmats.Bx8998, bmats.Bx8999, bmats.Bx9000, bmats.Bx9001, bmats.Bx9002, bmats.Bx9003, bmats.Bx9005, };
    double B_coeffs[17] = {-1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_9.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
