#include "stdafx.h"
#include "fBx9243.h"

inline int fBx9243(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_25_8, bmats.B_27_8, bmats.B_28_8, bmats.B_30_8, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9243.data[0][0], 0, sizeof(bmats.Bx9243.data[0][0])*bmats.Bx9243.shape[0]*bmats.Bx9243.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9243, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
