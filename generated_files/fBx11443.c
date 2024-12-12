#include "stdafx.h"
#include "fBx11443.h"

inline int fBx11443(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_16_21, bmats.Bx11442, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11443.data[0][0], 0, sizeof(bmats.Bx11443.data[0][0])*bmats.Bx11443.shape[0]*bmats.Bx11443.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11443, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
