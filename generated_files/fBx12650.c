#include "stdafx.h"
#include "fBx12650.h"

inline int fBx12650(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_2, bmats.B_2_19, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12650.data[0][0], 0, sizeof(bmats.Bx12650.data[0][0])*bmats.Bx12650.shape[0]*bmats.Bx12650.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12650, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
