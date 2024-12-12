#include "stdafx.h"
#include "fBx7419.h"

inline int fBx7419(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx4912, bmats.Bx7417, bmats.Bx7418, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7419.data[0][0], 0, sizeof(bmats.Bx7419.data[0][0])*bmats.Bx7419.shape[0]*bmats.Bx7419.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7419, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
