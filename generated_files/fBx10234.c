#include "stdafx.h"
#include "fBx10234.h"

inline int fBx10234(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_21_23, bmats.B_22_23, bmats.Bx10232, bmats.Bx10233, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx10234.data[0][0], 0, sizeof(bmats.Bx10234.data[0][0])*bmats.Bx10234.shape[0]*bmats.Bx10234.shape[1]);
    matlincomb_double_contiguous(bmats.Bx10234, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
