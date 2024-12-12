#include "stdafx.h"
#include "fBx13400.h"

inline int fBx13400(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_19_31, bmats.B_23_31, bmats.B_24_31, bmats.Bx13390, bmats.Bx13394, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx13400.data[0][0], 0, sizeof(bmats.Bx13400.data[0][0])*bmats.Bx13400.shape[0]*bmats.Bx13400.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13400, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
