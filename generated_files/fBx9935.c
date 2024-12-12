#include "stdafx.h"
#include "fBx9935.h"

inline int fBx9935(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_21_21, bmats.B_21_25, bmats.Bx9934, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9935.data[0][0], 0, sizeof(bmats.Bx9935.data[0][0])*bmats.Bx9935.shape[0]*bmats.Bx9935.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9935, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
