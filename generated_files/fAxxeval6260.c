#include "stdafx.h"
#include "fAxxeval6260.h"

inline int fAxxeval6260(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1988.data[0][0], 0, sizeof(bmats.Axx1988.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2026, bmats.Axx2165, bmats.Axx2182, bmats.Axx2185, bmats.Axx2186, bmats.Axx2189, bmats.Axx2190, bmats.Axx2193, bmats.Axx2194, bmats.Axx2197, bmats.Axx2202, bmats.Axx523, bmats.Axx87, bmats.Axx940, bmats.Axx943, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1988, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}