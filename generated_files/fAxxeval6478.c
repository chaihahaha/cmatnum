#include "stdafx.h"
#include "fAxxeval6478.h"

inline int fAxxeval6478(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1787.data[0][0], 0, sizeof(bmats.Axx1787.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_14_10, bmats.Axx2121, bmats.Axx3055, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1787, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
