#include "stdafx.h"
#include "fBx12067.h"

inline int fBx12067(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_20_4, bmats.B_31_4, bmats.B_32_4, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12067.data[0][0], 0, sizeof(bmats.Bx12067.data[0][0])*bmats.Bx12067.shape[0]*bmats.Bx12067.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12067, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
