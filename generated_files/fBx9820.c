#include "stdafx.h"
#include "fBx9820.h"

inline int fBx9820(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_14_24, bmats.B_8_24, bmats.B_9_24, bmats.Bx9679, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9820.data[0][0], 0, sizeof(bmats.Bx9820.data[0][0])*bmats.Bx9820.shape[0]*bmats.Bx9820.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9820, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
