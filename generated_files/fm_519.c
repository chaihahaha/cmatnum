#include "stdafx.h"
#include "fm_519.h"

inline int fm_519(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx1501, bmats.Axx2939, bmats.Axx2942, bmats.Axx2944, bmats.Axx2945, bmats.Axx2947, bmats.Axx2950, bmats.Axx2951, bmats.Axx2954, bmats.Axx2955, bmats.Axx2958, bmats.Axx2960, bmats.Axx2961, bmats.Axx2964, bmats.Axx2965, bmats.Axx2975, bmats.Axx78, bmats.Axx975, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx3196, bmats.Bx4396, bmats.Bx4466, bmats.Bx4481, bmats.Bx4482, bmats.Bx4483, bmats.Bx4484, bmats.Bx4485, bmats.Bx4486, bmats.Bx4487, bmats.Bx4488, bmats.Bx4489, bmats.Bx4490, bmats.Bx4491, bmats.Bx4492, bmats.Bx4493, bmats.Bx4494, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_17_13.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
