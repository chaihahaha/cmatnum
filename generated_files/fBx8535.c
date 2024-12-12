#include "stdafx.h"
#include "fBx8535.h"

inline int fBx8535(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_14_12, bmats.B_14_3, bmats.B_14_4, bmats.B_14_6, bmats.B_14_8, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx8535.data[0][0], 0, sizeof(bmats.Bx8535.data[0][0])*bmats.Bx8535.shape[0]*bmats.Bx8535.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8535, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
