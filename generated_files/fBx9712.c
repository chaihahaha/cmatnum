#include "stdafx.h"
#include "fBx9712.h"

inline int fBx9712(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_24_19, bmats.B_3_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9712.data[0][0], 0, sizeof(bmats.Bx9712.data[0][0])*bmats.Bx9712.shape[0]*bmats.Bx9712.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9712, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
