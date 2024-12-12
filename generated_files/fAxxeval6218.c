#include "stdafx.h"
#include "fAxxeval6218.h"

inline int fAxxeval6218(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2166.data[0][0], 0, sizeof(bmats.Axx2166.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1778, bmats.Axx2441, bmats.Axx2444, bmats.Axx2446, bmats.Axx2448, bmats.Axx2450, bmats.Axx2451, bmats.Axx2454, bmats.Axx2455, bmats.Axx2459, bmats.Axx2462, bmats.Axx2463, bmats.Axx2466, bmats.Axx2471, bmats.Axx961, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2166, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
