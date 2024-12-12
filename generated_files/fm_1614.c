#include "stdafx.h"
#include "fm_1614.h"

inline int fm_1614(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2029, bmats.Axx520, bmats.Axx548, bmats.Axx700, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.B_11_4, bmats.B_14_4, bmats.B_2_4, bmats.B_3_4, bmats.B_4_4, bmats.B_5_4, bmats.B_6_4, bmats.B_7_4, bmats.B_8_4, bmats.B_9_4, bmats.Bx12108, bmats.Bx12153, bmats.Bx12154, bmats.Bx12155, bmats.Bx12156, bmats.Bx3212, bmats.Bx3240, bmats.Bx4970, bmats.Bx7665, };
    double B_coeffs[19] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_9_4.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
