#include "stdafx.h"
#include "fBx8901.h"

inline int fBx8901(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_17_9, bmats.B_7_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8901.data[0][0], 0, sizeof(bmats.Bx8901.data[0][0])*bmats.Bx8901.shape[0]*bmats.Bx8901.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8901, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
