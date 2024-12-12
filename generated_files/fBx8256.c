#include "stdafx.h"
#include "fBx8256.h"

inline int fBx8256(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_20_25, bmats.B_21_25, bmats.B_22_25, bmats.B_23_25, bmats.B_24_25, bmats.Bx8255, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx8256.data[0][0], 0, sizeof(bmats.Bx8256.data[0][0])*bmats.Bx8256.shape[0]*bmats.Bx8256.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8256, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
