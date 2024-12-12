#include "stdafx.h"
#include "fm_278.h"

inline int fm_278(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx2045, bmats.Axx3379, bmats.Axx384, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_30_30, bmats.Bx967, bmats.Bx983, bmats.Bx984, bmats.Bx985, bmats.Bx986, bmats.Bx987, bmats.Bx988, bmats.Bx989, bmats.Bx990, bmats.Bx991, bmats.Bx992, bmats.Bx993, bmats.Bx994, bmats.Bx995, bmats.Bx996, bmats.Bx997, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_16_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
