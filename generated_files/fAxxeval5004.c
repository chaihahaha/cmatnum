#include "stdafx.h"
#include "fAxxeval5004.h"

inline int fAxxeval5004(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3125.data[0][0], 0, sizeof(bmats.Axx3125.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx142, bmats.Axx1515, bmats.Axx1521, bmats.Axx1896, bmats.Axx1980, bmats.Axx2132, bmats.Axx2156, bmats.Axx2473, bmats.Axx2540, bmats.Axx2852, bmats.Axx2938, bmats.Axx3350, bmats.Axx3396, bmats.Axx394, bmats.Axx998, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3125, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
