#include "stdafx.h"
#include "fBx9347.h"

inline int fBx9347(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_1_4, bmats.Bx2753, bmats.Bx5745, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9347.data[0][0], 0, sizeof(bmats.Bx9347.data[0][0])*bmats.Bx9347.shape[0]*bmats.Bx9347.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9347, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}