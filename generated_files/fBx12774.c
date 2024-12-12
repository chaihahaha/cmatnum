#include "stdafx.h"
#include "fBx12774.h"

inline int fBx12774(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_2_9, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx12774.data[0][0], 0, sizeof(bmats.Bx12774.data[0][0])*bmats.Bx12774.shape[0]*bmats.Bx12774.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12774, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
