#include "stdafx.h"
#include "fm_1500.h"

inline int fm_1500(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2107, bmats.Axx443, bmats.Axx479, bmats.Axx521, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 9;
    double_cmat B_mats[9] = {bmats.B_3_5, bmats.Bx11349, bmats.Bx11758, bmats.Bx11759, bmats.Bx11760, bmats.Bx11761, bmats.Bx11762, bmats.Bx11763, bmats.Bx9023, };
    double B_coeffs[9] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_3_5.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
