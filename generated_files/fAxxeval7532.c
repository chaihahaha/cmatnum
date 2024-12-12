#include "stdafx.h"
#include "fAxxeval7532.h"

inline int fAxxeval7532(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2435.data[0][0], 0, sizeof(bmats.Axx2435.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_26_27, bmats.Axx1368, bmats.Axx1751, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2435, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
