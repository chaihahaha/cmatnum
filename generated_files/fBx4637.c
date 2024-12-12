#include "stdafx.h"
#include "fBx4637.h"

inline int fBx4637(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 11;
    double_cmat B_mats[11] = {bmats.B_10_28, bmats.B_11_28, bmats.B_3_28, bmats.B_4_28, bmats.B_5_28, bmats.B_6_28, bmats.B_7_28, bmats.B_8_28, bmats.Bx4213, bmats.Bx4326, bmats.Bx4636, };
    double B_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx4637.data[0][0], 0, sizeof(bmats.Bx4637.data[0][0])*bmats.Bx4637.shape[0]*bmats.Bx4637.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4637, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
