#include "stdafx.h"
#include "fm_1878.h"

inline int fm_1878(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1753, bmats.Axx1978, bmats.Axx750, bmats.Axx760, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_7_2, bmats.B_7_5, bmats.B_7_8, bmats.Bx12197, bmats.Bx12680, bmats.Bx12800, bmats.Bx12801, bmats.Bx12802, bmats.Bx7666, bmats.Bx9623, };
    double B_coeffs[10] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_7_2.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
