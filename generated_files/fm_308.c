#include "stdafx.h"
#include "fm_308.h"

inline int fm_308(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx2665, bmats.Axx281, bmats.Axx318, bmats.Axx353, };
    double A_coeffs[4] = {1, 1, 1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.B_24_30, bmats.Bx1449, bmats.Bx1450, bmats.Bx1451, bmats.Bx1452, bmats.Bx1453, bmats.Bx1454, bmats.Bx1455, bmats.Bx1456, bmats.Bx1457, bmats.Bx1458, bmats.Bx1459, bmats.Bx1460, bmats.Bx1461, bmats.Bx1462, bmats.Bx1463, bmats.Bx1464, };
    double B_coeffs[17] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_24_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
