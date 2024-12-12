#include "stdafx.h"
#include "fBx12140.h"

inline int fBx12140(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_23_15, bmats.B_23_16, bmats.B_23_7, bmats.Bx11066, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12140.data[0][0], 0, sizeof(bmats.Bx12140.data[0][0])*bmats.Bx12140.shape[0]*bmats.Bx12140.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12140, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
