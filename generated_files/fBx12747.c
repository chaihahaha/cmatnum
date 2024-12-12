#include "stdafx.h"
#include "fBx12747.h"

inline int fBx12747(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_27_10, bmats.B_27_11, bmats.B_27_15, bmats.B_27_16, bmats.Bx7427, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12747.data[0][0], 0, sizeof(bmats.Bx12747.data[0][0])*bmats.Bx12747.shape[0]*bmats.Bx12747.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12747, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
