#include "stdafx.h"
#include "fBx12278.h"

inline int fBx12278(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_19_19, bmats.B_21_19, bmats.B_22_19, bmats.B_23_19, bmats.B_25_19, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12278.data[0][0], 0, sizeof(bmats.Bx12278.data[0][0])*bmats.Bx12278.shape[0]*bmats.Bx12278.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12278, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
