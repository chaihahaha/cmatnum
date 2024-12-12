#include "stdafx.h"
#include "fBx10008.h"

inline int fBx10008(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_24_7, bmats.B_25_7, bmats.B_26_7, bmats.B_28_7, bmats.B_30_7, bmats.Bx10007, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx10008.data[0][0], 0, sizeof(bmats.Bx10008.data[0][0])*bmats.Bx10008.shape[0]*bmats.Bx10008.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10008, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
