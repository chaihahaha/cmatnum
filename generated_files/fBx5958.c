#include "stdafx.h"
#include "fBx5958.h"

inline int fBx5958(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_16_11, bmats.Bx5955, bmats.Bx5956, bmats.Bx5957, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx5958.data[0][0], 0, sizeof(bmats.Bx5958.data[0][0])*bmats.Bx5958.shape[0]*bmats.Bx5958.shape[1]);
    matlincomb_double_contiguous(bmats.Bx5958, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
