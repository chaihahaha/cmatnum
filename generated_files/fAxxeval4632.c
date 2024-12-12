#include "stdafx.h"
#include "fAxxeval4632.h"

inline int fAxxeval4632(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3349.data[0][0], 0, sizeof(bmats.Axx3349.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2218, bmats.Axx2277, bmats.Axx2351, bmats.Axx2419, bmats.Axx2487, bmats.Axx2550, bmats.Axx2612, bmats.Axx2692, bmats.Axx2763, bmats.Axx2836, bmats.Axx2902, bmats.Axx2982, bmats.Axx3066, bmats.Axx3143, bmats.Axx3231, bmats.Axx3348, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3349, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
