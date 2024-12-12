#include "stdafx.h"
#include "fBx13358.h"

inline int fBx13358(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_16_15, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx13358.data[0][0], 0, sizeof(bmats.Bx13358.data[0][0])*bmats.Bx13358.shape[0]*bmats.Bx13358.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13358, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
