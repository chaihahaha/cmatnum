#include "stdafx.h"
#include "fBx69.h"

inline int fBx69(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_27, bmats.B_27_22, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx69.data[0][0], 0, sizeof(bmats.Bx69.data[0][0])*bmats.Bx69.shape[0]*bmats.Bx69.shape[1]);
    matlincomb_double_contiguous(bmats.Bx69, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
