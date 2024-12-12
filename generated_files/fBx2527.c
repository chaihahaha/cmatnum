#include "stdafx.h"
#include "fBx2527.h"

inline int fBx2527(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx2526, bmats.Bx850, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2527.data[0][0], 0, sizeof(bmats.Bx2527.data[0][0])*bmats.Bx2527.shape[0]*bmats.Bx2527.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2527, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
