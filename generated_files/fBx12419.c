#include "stdafx.h"
#include "fBx12419.h"

inline int fBx12419(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12417, bmats.Bx12418, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12419.data[0][0], 0, sizeof(bmats.Bx12419.data[0][0])*bmats.Bx12419.shape[0]*bmats.Bx12419.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12419, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
