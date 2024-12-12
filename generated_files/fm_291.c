#include "stdafx.h"
#include "fm_291.h"

inline int fm_291(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2617, bmats.Axx309, bmats.Axx360, bmats.Axx857, };
    double A_coeffs[4] = {1, 1, -1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_28_28, bmats.B_28_30, bmats.B_30_30, bmats.Bx1185, bmats.Bx1186, bmats.Bx1187, bmats.Bx1188, bmats.Bx1189, bmats.Bx1190, bmats.Bx1191, bmats.Bx1192, bmats.Bx1193, bmats.Bx1194, bmats.Bx1195, bmats.Bx1196, bmats.Bx1197, bmats.Bx1198, bmats.Bx1199, };
    double B_coeffs[18] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_28_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
