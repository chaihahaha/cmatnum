#include "stdafx.h"
#include "fm_908.h"

inline int fm_908(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1392, bmats.Axx1394, bmats.Axx1579, bmats.Axx2883, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 18;
    double_cmat B_mats[18] = {bmats.B_17_26, bmats.B_25_26, bmats.B_27_26, bmats.B_29_26, bmats.Bx2, bmats.Bx2796, bmats.Bx7414, bmats.Bx8005, bmats.Bx8468, bmats.Bx8469, bmats.Bx8470, bmats.Bx8471, bmats.Bx8472, bmats.Bx8473, bmats.Bx8474, bmats.Bx8475, bmats.Bx8476, bmats.Bx8477, };
    double B_coeffs[18] = {-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
