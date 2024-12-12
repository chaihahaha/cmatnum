#include "stdafx.h"
#include "fBx9106.h"

inline int fBx9106(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_4_10, bmats.B_4_12, bmats.Bx9105, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9106.data[0][0], 0, sizeof(bmats.Bx9106.data[0][0])*bmats.Bx9106.shape[0]*bmats.Bx9106.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9106, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
