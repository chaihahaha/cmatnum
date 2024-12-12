#include "stdafx.h"
#include "fBx8799.h"

inline int fBx8799(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_3_9, bmats.B_6_19, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8799.data[0][0], 0, sizeof(bmats.Bx8799.data[0][0])*bmats.Bx8799.shape[0]*bmats.Bx8799.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8799, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
