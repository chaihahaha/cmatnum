#include "stdafx.h"
#include "fAxxeval4645.h"

inline int fAxxeval4645(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3360.data[0][0], 0, sizeof(bmats.Axx3360.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2224, bmats.Axx2291, bmats.Axx2358, bmats.Axx2426, bmats.Axx2494, bmats.Axx2556, bmats.Axx2624, bmats.Axx2696, bmats.Axx2769, bmats.Axx2841, bmats.Axx2919, bmats.Axx2992, bmats.Axx3070, bmats.Axx3148, bmats.Axx3211, bmats.Axx3357, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3360, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
