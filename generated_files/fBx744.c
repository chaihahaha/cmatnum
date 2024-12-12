#include "stdafx.h"
#include "fBx744.h"

inline int fBx744(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_30_29, bmats.B_30_30, bmats.B_30_32, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx744.data[0][0], 0, sizeof(bmats.Bx744.data[0][0])*bmats.Bx744.shape[0]*bmats.Bx744.shape[1]);
    matlincomb_double_contiguous(bmats.Bx744, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
