#include "stdafx.h"
#include "fBx4129.h"

inline int fBx4129(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_4_29, bmats.B_4_30, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4129.data[0][0], 0, sizeof(bmats.Bx4129.data[0][0])*bmats.Bx4129.shape[0]*bmats.Bx4129.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4129, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
