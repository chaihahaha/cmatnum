#include "stdafx.h"
#include "fBx8279.h"

inline int fBx8279(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_4_25, bmats.B_6_25, bmats.B_7_25, bmats.Bx8275, bmats.Bx8277, bmats.Bx8278, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx8279.data[0][0], 0, sizeof(bmats.Bx8279.data[0][0])*bmats.Bx8279.shape[0]*bmats.Bx8279.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8279, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
