#include "stdafx.h"
#include "fBx12989.h"

inline int fBx12989(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 10;
    double_cmat B_mats[10] = {bmats.B_12_17, bmats.B_15_17, bmats.B_16_17, bmats.B_3_17, bmats.B_7_17, bmats.B_8_17, bmats.B_9_17, bmats.Bx12862, bmats.Bx12941, bmats.Bx12970, };
    double B_coeffs[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12989.data[0][0], 0, sizeof(bmats.Bx12989.data[0][0])*bmats.Bx12989.shape[0]*bmats.Bx12989.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12989, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
