#include "stdafx.h"
#include "fBx9729.h"

inline int fBx9729(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_8_24, bmats.B_8_31, bmats.Bx8560, bmats.Bx9728, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9729.data[0][0], 0, sizeof(bmats.Bx9729.data[0][0])*bmats.Bx9729.shape[0]*bmats.Bx9729.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9729, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
