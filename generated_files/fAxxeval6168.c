#include "stdafx.h"
#include "fAxxeval6168.h"

inline int fAxxeval6168(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1790.data[0][0], 0, sizeof(bmats.Axx1790.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1995, bmats.Axx2646, bmats.Axx2648, bmats.Axx2649, bmats.Axx2652, bmats.Axx2653, bmats.Axx2656, bmats.Axx2658, bmats.Axx2659, bmats.Axx2662, bmats.Axx2663, bmats.Axx2670, bmats.Axx2671, bmats.Axx2680, bmats.Axx967, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1790, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
