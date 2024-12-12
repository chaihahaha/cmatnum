#include "stdafx.h"
#include "fBx4507.h"

inline int fBx4507(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx2224, bmats.Bx4506, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4507.data[0][0], 0, sizeof(bmats.Bx4507.data[0][0])*bmats.Bx4507.shape[0]*bmats.Bx4507.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4507, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
