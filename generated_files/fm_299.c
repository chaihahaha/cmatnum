#include "stdafx.h"
#include "fm_299.h"

inline int fm_299(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1794, bmats.Axx2665, bmats.Axx294, bmats.Axx366, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_29_30, bmats.Bx1308, bmats.Bx1309, bmats.Bx1310, bmats.Bx1311, bmats.Bx1312, bmats.Bx1313, bmats.Bx1314, bmats.Bx1315, bmats.Bx1316, bmats.Bx1317, bmats.Bx1318, bmats.Bx1319, bmats.Bx1320, bmats.Bx1321, bmats.Bx1322, bmats.Bx666, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_29_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
