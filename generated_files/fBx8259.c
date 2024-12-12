#include "stdafx.h"
#include "fBx8259.h"

inline int fBx8259(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_10_9, bmats.B_11_9, bmats.B_6_9, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx8259.data[0][0], 0, sizeof(bmats.Bx8259.data[0][0])*bmats.Bx8259.shape[0]*bmats.Bx8259.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8259, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
