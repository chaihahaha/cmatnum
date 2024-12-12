#include "stdafx.h"
#include "fm_1391.h"

inline int fm_1391(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx2089, bmats.Axx2125, bmats.Axx2238, bmats.Axx2241, bmats.Axx2243, bmats.Axx2244, bmats.Axx2247, bmats.Axx2248, bmats.Axx2251, bmats.Axx2252, bmats.Axx2255, bmats.Axx2256, bmats.Axx2259, bmats.Axx2260, bmats.Axx2263, bmats.Axx2264, bmats.Axx2270, bmats.Axx955, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.Bx11268, bmats.Bx11334, bmats.Bx11373, bmats.Bx11382, bmats.Bx11383, bmats.Bx11384, bmats.Bx11385, bmats.Bx11386, bmats.Bx11387, bmats.Bx11388, };
    double B_coeffs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_6.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
