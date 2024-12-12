#include "stdafx.h"
#include "fAxxeval4033.h"

inline int fAxxeval4033(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2899.data[0][0], 0, sizeof(bmats.Axx2899.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2860, bmats.Axx2861, bmats.Axx2863, bmats.Axx2866, bmats.Axx2868, bmats.Axx2869, bmats.Axx2872, bmats.Axx2873, bmats.Axx2875, bmats.Axx2878, bmats.Axx2880, bmats.Axx2881, bmats.Axx2883, bmats.Axx2886, bmats.Axx2898, bmats.Axx972, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2899, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
