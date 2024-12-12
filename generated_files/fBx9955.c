#include "stdafx.h"
#include "fBx9955.h"

inline int fBx9955(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_5_24, bmats.Bx8722, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9955.data[0][0], 0, sizeof(bmats.Bx9955.data[0][0])*bmats.Bx9955.shape[0]*bmats.Bx9955.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9955, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
