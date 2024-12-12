#include "stdafx.h"
#include "fBx13417.h"

inline int fBx13417(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_15_25, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx13417.data[0][0], 0, sizeof(bmats.Bx13417.data[0][0])*bmats.Bx13417.shape[0]*bmats.Bx13417.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13417, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
