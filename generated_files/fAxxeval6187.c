#include "stdafx.h"
#include "fAxxeval6187.h"

inline int fAxxeval6187(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2781.data[0][0], 0, sizeof(bmats.Axx2781.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2891, bmats.Axx3018, bmats.Axx3020, bmats.Axx3021, bmats.Axx3024, bmats.Axx3025, bmats.Axx3028, bmats.Axx3031, bmats.Axx3033, bmats.Axx3036, bmats.Axx3038, bmats.Axx3042, bmats.Axx3044, bmats.Axx3053, bmats.Axx976, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2781, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
