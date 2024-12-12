#include "stdafx.h"
#include "fAxxeval6109.h"

inline int fAxxeval6109(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2946.data[0][0], 0, sizeof(bmats.Axx2946.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2075, bmats.Axx2860, bmats.Axx2861, bmats.Axx2863, bmats.Axx2866, bmats.Axx2868, bmats.Axx2869, bmats.Axx2872, bmats.Axx2873, bmats.Axx2875, bmats.Axx2878, bmats.Axx2880, bmats.Axx2881, bmats.Axx2898, bmats.Axx972, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2946, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
