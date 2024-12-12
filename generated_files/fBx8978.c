#include "stdafx.h"
#include "fBx8978.h"

inline int fBx8978(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_18_7, bmats.B_7_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8978.data[0][0], 0, sizeof(bmats.Bx8978.data[0][0])*bmats.Bx8978.shape[0]*bmats.Bx8978.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8978, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
