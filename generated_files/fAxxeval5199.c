#include "stdafx.h"
#include "fAxxeval5199.h"

inline int fAxxeval5199(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2136.data[0][0], 0, sizeof(bmats.Axx2136.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx134, bmats.Axx1667, bmats.Axx1681, bmats.Axx2095, bmats.Axx2137, bmats.Axx2179, bmats.Axx2785, bmats.Axx2931, bmats.Axx3162, bmats.Axx3380, bmats.Axx4, bmats.Axx80, bmats.Axx834, bmats.Axx942, bmats.Axx999, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2136, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
