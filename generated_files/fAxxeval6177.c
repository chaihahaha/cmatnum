#include "stdafx.h"
#include "fAxxeval6177.h"

inline int fAxxeval6177(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx807.data[0][0], 0, sizeof(bmats.Axx807.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1761, bmats.Axx2570, bmats.Axx2572, bmats.Axx2574, bmats.Axx2575, bmats.Axx2577, bmats.Axx2580, bmats.Axx2582, bmats.Axx2583, bmats.Axx2586, bmats.Axx2587, bmats.Axx2590, bmats.Axx2591, bmats.Axx2595, bmats.Axx965, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx807, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}