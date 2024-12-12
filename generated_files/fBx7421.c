#include "stdafx.h"
#include "fBx7421.h"

inline int fBx7421(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_11_7, bmats.Bx3440, bmats.Bx6215, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7421.data[0][0], 0, sizeof(bmats.Bx7421.data[0][0])*bmats.Bx7421.shape[0]*bmats.Bx7421.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7421, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
