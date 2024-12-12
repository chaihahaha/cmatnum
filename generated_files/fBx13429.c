#include "stdafx.h"
#include "fBx13429.h"

inline int fBx13429(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_31, bmats.B_27_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx13429.data[0][0], 0, sizeof(bmats.Bx13429.data[0][0])*bmats.Bx13429.shape[0]*bmats.Bx13429.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13429, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
