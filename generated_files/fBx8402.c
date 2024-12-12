#include "stdafx.h"
#include "fBx8402.h"

inline int fBx8402(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_20, bmats.B_4_25, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8402.data[0][0], 0, sizeof(bmats.Bx8402.data[0][0])*bmats.Bx8402.shape[0]*bmats.Bx8402.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8402, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
