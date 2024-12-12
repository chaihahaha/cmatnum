#include "stdafx.h"
#include "fAxxeval7611.h"

inline int fAxxeval7611(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx688.data[0][0], 0, sizeof(bmats.Axx688.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1851, bmats.Axx2035, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx688, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
