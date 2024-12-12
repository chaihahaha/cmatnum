#include "stdafx.h"
#include "fBx9974.h"

inline int fBx9974(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_6_7, bmats.B_7_8, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9974.data[0][0], 0, sizeof(bmats.Bx9974.data[0][0])*bmats.Bx9974.shape[0]*bmats.Bx9974.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9974, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
