#include "stdafx.h"
#include "fBx12097.h"

inline int fBx12097(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12096, bmats.Bx8328, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12097.data[0][0], 0, sizeof(bmats.Bx12097.data[0][0])*bmats.Bx12097.shape[0]*bmats.Bx12097.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12097, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
