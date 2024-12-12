#include "stdafx.h"
#include "fAxxeval6149.h"

inline int fAxxeval6149(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx895.data[0][0], 0, sizeof(bmats.Axx895.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2070, bmats.Axx2789, bmats.Axx2792, bmats.Axx2798, bmats.Axx2800, bmats.Axx2802, bmats.Axx2803, bmats.Axx2806, bmats.Axx2807, bmats.Axx2810, bmats.Axx2811, bmats.Axx2814, bmats.Axx2815, bmats.Axx2821, bmats.Axx971, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx895, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
