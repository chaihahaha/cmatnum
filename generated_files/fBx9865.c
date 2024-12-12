#include "stdafx.h"
#include "fBx9865.h"

inline int fBx9865(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_20_20, bmats.Bx9864, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9865.data[0][0], 0, sizeof(bmats.Bx9865.data[0][0])*bmats.Bx9865.shape[0]*bmats.Bx9865.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9865, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
