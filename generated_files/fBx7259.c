#include "stdafx.h"
#include "fBx7259.h"

inline int fBx7259(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_31_24, bmats.B_8_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7259.data[0][0], 0, sizeof(bmats.Bx7259.data[0][0])*bmats.Bx7259.shape[0]*bmats.Bx7259.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7259, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
