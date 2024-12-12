#include "stdafx.h"
#include "fm_547.h"

inline int fm_547(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1460, bmats.Axx1462, bmats.Axx2044, bmats.Axx2435, };
    double A_coeffs[4] = {-1, 1, 1, 1, };
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.B_25_28, bmats.Bx30, bmats.Bx31, bmats.Bx32, bmats.Bx3255, bmats.Bx33, bmats.Bx34, bmats.Bx35, bmats.Bx4226, bmats.Bx4624, bmats.Bx4675, bmats.Bx4676, bmats.Bx4677, bmats.Bx4678, bmats.Bx4679, bmats.Bx4680, };
    double B_coeffs[16] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_28.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
