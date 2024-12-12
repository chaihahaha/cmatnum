#include "stdafx.h"
#include "fAxxeval7456.h"

inline int fAxxeval7456(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx631.data[0][0], 0, sizeof(bmats.Axx631.data[0][0])*BL*BL);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.Axx1358, bmats.Axx1360, bmats.Axx1644, bmats.Axx2895, bmats.Axx3133, bmats.Axx404, bmats.Axx643, };
    double A_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx631, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
