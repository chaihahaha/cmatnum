#include "stdafx.h"
#include "fm_758.h"

inline int fm_758(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx2303, bmats.Axx2861, bmats.Axx3095, bmats.Axx3096, bmats.Axx3098, bmats.Axx3101, bmats.Axx3103, bmats.Axx3104, bmats.Axx3106, bmats.Axx3109, bmats.Axx3110, bmats.Axx3113, bmats.Axx3114, bmats.Axx3117, bmats.Axx3119, bmats.Axx3120, bmats.Axx3130, bmats.Axx979, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 15;
    double_cmat B_mats[15] = {bmats.Bx6311, bmats.Bx7007, bmats.Bx7068, bmats.Bx7081, bmats.Bx7082, bmats.Bx7083, bmats.Bx7084, bmats.Bx7085, bmats.Bx7086, bmats.Bx7087, bmats.Bx7088, bmats.Bx7089, bmats.Bx7090, bmats.Bx7091, bmats.Bx7092, };
    double B_coeffs[15] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_18_11.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
