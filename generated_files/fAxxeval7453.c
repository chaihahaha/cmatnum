#include "stdafx.h"
#include "fAxxeval7453.h"

inline int fAxxeval7453(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2283.data[0][0], 0, sizeof(bmats.Axx2283.data[0][0])*BL*BL);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.Axx1358, bmats.Axx1360, bmats.Axx2305, bmats.Axx2895, bmats.Axx3133, bmats.Axx404, };
    double A_coeffs[6] = {1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2283, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
