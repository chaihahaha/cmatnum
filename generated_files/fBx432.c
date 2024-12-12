#include "stdafx.h"
#include "fBx432.h"

inline int fBx432(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_28, bmats.B_28_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx432.data[0][0], 0, sizeof(bmats.Bx432.data[0][0])*bmats.Bx432.shape[0]*bmats.Bx432.shape[1]);
    matlincomb_double_contiguous(bmats.Bx432, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
