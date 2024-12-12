#include "stdafx.h"
#include "fBx9488.h"

inline int fBx9488(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_14_12, bmats.B_14_3, bmats.B_14_4, bmats.B_14_9, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9488.data[0][0], 0, sizeof(bmats.Bx9488.data[0][0])*bmats.Bx9488.shape[0]*bmats.Bx9488.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9488, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
