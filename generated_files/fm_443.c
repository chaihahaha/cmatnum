#include "stdafx.h"
#include "fm_443.h"

inline int fm_443(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1501, bmats.Axx1873, bmats.Axx2610, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx2498, bmats.Bx3356, bmats.Bx3386, bmats.Bx3387, bmats.Bx3388, bmats.Bx3389, bmats.Bx3390, bmats.Bx3391, bmats.Bx3392, bmats.Bx3393, bmats.Bx3394, bmats.Bx3395, bmats.Bx3396, bmats.Bx3397, bmats.Bx3398, bmats.Bx3399, bmats.Bx3400, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_26_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
