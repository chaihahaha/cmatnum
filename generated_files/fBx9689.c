#include "stdafx.h"
#include "fBx9689.h"

inline int fBx9689(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_8, bmats.B_7_22, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9689.data[0][0], 0, sizeof(bmats.Bx9689.data[0][0])*bmats.Bx9689.shape[0]*bmats.Bx9689.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9689, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
