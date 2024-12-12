#include "stdafx.h"
#include "fAxxeval3705.h"

inline int fAxxeval3705(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2609.data[0][0], 0, sizeof(bmats.Axx2609.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2570, bmats.Axx2572, bmats.Axx2574, bmats.Axx2575, bmats.Axx2577, bmats.Axx2580, bmats.Axx2582, bmats.Axx2583, bmats.Axx2586, bmats.Axx2587, bmats.Axx2590, bmats.Axx2591, bmats.Axx2594, bmats.Axx2595, bmats.Axx2605, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2609, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
