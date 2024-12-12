#include "stdafx.h"
#include "fBx9517.h"

inline int fBx9517(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_9_2, bmats.B_9_6, bmats.B_9_8, bmats.Bx5290, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9517.data[0][0], 0, sizeof(bmats.Bx9517.data[0][0])*bmats.Bx9517.shape[0]*bmats.Bx9517.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9517, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
