#include "stdafx.h"
#include "fBx11066.h"

inline int fBx11066(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_23_1, bmats.B_23_2, bmats.B_23_3, bmats.B_23_4, bmats.B_23_5, bmats.B_23_6, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx11066.data[0][0], 0, sizeof(bmats.Bx11066.data[0][0])*bmats.Bx11066.shape[0]*bmats.Bx11066.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11066, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
