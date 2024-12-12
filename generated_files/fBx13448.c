#include "stdafx.h"
#include "fBx13448.h"

inline int fBx13448(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_17_32, bmats.B_19_32, bmats.B_26_32, bmats.Bx13382, bmats.Bx13440, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx13448.data[0][0], 0, sizeof(bmats.Bx13448.data[0][0])*bmats.Bx13448.shape[0]*bmats.Bx13448.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13448, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
