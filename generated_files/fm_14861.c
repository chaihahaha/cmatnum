#include "stdafx.h"
#include "fm_14861.h"

inline int fm_14861(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1925, bmats.Axx298, bmats.Axx3165, bmats.Axx3168, bmats.Axx3169, bmats.Axx3172, bmats.Axx3173, bmats.Axx3176, bmats.Axx3177, bmats.Axx3180, bmats.Axx3181, bmats.Axx3183, bmats.Axx3185, bmats.Axx3188, bmats.Axx3189, bmats.Axx3192, bmats.Axx3197, bmats.Axx980, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx13206, bmats.Bx13236, bmats.Bx13385, };
    double B_coeffs[3] = {-1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_32_15.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
