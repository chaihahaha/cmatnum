#include "stdafx.h"
#include "fAxxeval3554.h"

inline int fAxxeval3554(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2481.data[0][0], 0, sizeof(bmats.Axx2481.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2441, bmats.Axx2444, bmats.Axx2446, bmats.Axx2448, bmats.Axx2450, bmats.Axx2451, bmats.Axx2454, bmats.Axx2455, bmats.Axx2458, bmats.Axx2459, bmats.Axx2462, bmats.Axx2463, bmats.Axx2466, bmats.Axx2467, bmats.Axx2471, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2481, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
