#include "stdafx.h"
#include "fBx4109.h"

inline int fBx4109(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_9, bmats.B_25_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4109.data[0][0], 0, sizeof(bmats.Bx4109.data[0][0])*bmats.Bx4109.shape[0]*bmats.Bx4109.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4109, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
