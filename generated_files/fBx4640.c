#include "stdafx.h"
#include "fBx4640.h"

inline int fBx4640(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx4226, bmats.Bx4625, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx4640.data[0][0], 0, sizeof(bmats.Bx4640.data[0][0])*bmats.Bx4640.shape[0]*bmats.Bx4640.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4640, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
