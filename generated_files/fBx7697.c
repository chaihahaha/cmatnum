#include "stdafx.h"
#include "fBx7697.h"

inline int fBx7697(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_26_23, bmats.B_26_24, bmats.B_26_25, bmats.B_26_27, bmats.B_26_31, bmats.B_26_32, bmats.Bx4811, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx7697.data[0][0], 0, sizeof(bmats.Bx7697.data[0][0])*bmats.Bx7697.shape[0]*bmats.Bx7697.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7697, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
