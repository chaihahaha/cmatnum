#include "stdafx.h"
#include "fAxxeval6209.h"

inline int fAxxeval6209(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2239.data[0][0], 0, sizeof(bmats.Axx2239.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2091, bmats.Axx2376, bmats.Axx2378, bmats.Axx2380, bmats.Axx2381, bmats.Axx2384, bmats.Axx2385, bmats.Axx2388, bmats.Axx2389, bmats.Axx2396, bmats.Axx2397, bmats.Axx2400, bmats.Axx2402, bmats.Axx2406, bmats.Axx958, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2239, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
