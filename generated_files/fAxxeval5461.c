#include "stdafx.h"
#include "fAxxeval5461.h"

inline int fAxxeval5461(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx157.data[0][0], 0, sizeof(bmats.Axx157.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1008, bmats.Axx1523, bmats.Axx1733, bmats.Axx1735, bmats.Axx1805, bmats.Axx2114, bmats.Axx3049, bmats.Axx3126, bmats.Axx3289, bmats.Axx3291, bmats.Axx3360, bmats.Axx3380, bmats.Axx380, bmats.Axx4, bmats.Axx942, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx157, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}