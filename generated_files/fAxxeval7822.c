#include "stdafx.h"
#include "fAxxeval7822.h"

inline int fAxxeval7822(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx602.data[0][0], 0, sizeof(bmats.Axx602.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_24_17, bmats.A_24_18, bmats.A_24_19, bmats.A_24_20, bmats.A_24_23, bmats.A_24_24, bmats.A_24_25, bmats.A_24_26, bmats.A_24_27, bmats.A_24_28, bmats.A_24_29, bmats.A_24_30, bmats.A_24_31, bmats.A_24_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx602, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}