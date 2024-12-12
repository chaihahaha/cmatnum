#include "stdafx.h"
#include "fAxxeval6198.h"

inline int fAxxeval6198(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2122.data[0][0], 0, sizeof(bmats.Axx2122.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2303, bmats.Axx3095, bmats.Axx3097, bmats.Axx3098, bmats.Axx3101, bmats.Axx3103, bmats.Axx3104, bmats.Axx3106, bmats.Axx3109, bmats.Axx3110, bmats.Axx3113, bmats.Axx3114, bmats.Axx3117, bmats.Axx3120, bmats.Axx979, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2122, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
