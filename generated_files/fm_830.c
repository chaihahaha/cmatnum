#include "stdafx.h"
#include "fm_830.h"

inline int fm_830(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1761, bmats.Axx1947, bmats.Axx2685, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.Bx7311, bmats.Bx7605, bmats.Bx7629, bmats.Bx7630, bmats.Bx7631, bmats.Bx7632, bmats.Bx7633, bmats.Bx7634, bmats.Bx7635, bmats.Bx7636, bmats.Bx7637, bmats.Bx7638, bmats.Bx7639, bmats.Bx7640, };
    double B_coeffs[14] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_10.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
