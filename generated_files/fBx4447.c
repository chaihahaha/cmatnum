#include "stdafx.h"
#include "fBx4447.h"

inline int fBx4447(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_8, bmats.B_24_29, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4447.data[0][0], 0, sizeof(bmats.Bx4447.data[0][0])*bmats.Bx4447.shape[0]*bmats.Bx4447.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4447, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
