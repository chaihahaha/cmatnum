#include "stdafx.h"
#include "fBx12073.h"

inline int fBx12073(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_14_4, bmats.B_6_4, bmats.B_9_4, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12073.data[0][0], 0, sizeof(bmats.Bx12073.data[0][0])*bmats.Bx12073.shape[0]*bmats.Bx12073.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12073, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
