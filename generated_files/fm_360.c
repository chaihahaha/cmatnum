#include "stdafx.h"
#include "fm_360.h"

inline int fm_360(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1706, bmats.Axx3379, bmats.Axx394, };
    double A_coeffs[3] = {1, 1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_18_14, bmats.B_30_30, bmats.Bx2210, bmats.Bx2242, bmats.Bx2243, bmats.Bx2244, bmats.Bx2245, bmats.Bx2246, bmats.Bx2247, bmats.Bx2248, bmats.Bx2249, bmats.Bx2250, bmats.Bx2251, bmats.Bx2252, bmats.Bx2253, bmats.Bx2254, bmats.Bx2255, bmats.Bx2256, };
    double B_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_2_30.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
