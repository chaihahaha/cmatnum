#include "stdafx.h"
#include "fm_1276.h"

inline int fm_1276(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 18;
    double_cmat A_mats[18] = {bmats.Axx2070, bmats.Axx2125, bmats.Axx2789, bmats.Axx2792, bmats.Axx2793, bmats.Axx2796, bmats.Axx2798, bmats.Axx2799, bmats.Axx2802, bmats.Axx2803, bmats.Axx2806, bmats.Axx2807, bmats.Axx2810, bmats.Axx2811, bmats.Axx2814, bmats.Axx2815, bmats.Axx2821, bmats.Axx971, };
    double A_coeffs[18] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.Bx10526, bmats.Bx10817, bmats.Bx10862, bmats.Bx10871, bmats.Bx10872, bmats.Bx10873, bmats.Bx10874, bmats.Bx10875, bmats.Bx10876, bmats.Bx10877, bmats.Bx10878, };
    double B_coeffs[11] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_19_7.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
