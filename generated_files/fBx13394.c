#include "stdafx.h"
#include "fBx13394.h"

inline int fBx13394(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_18_31, bmats.B_30_31, bmats.Bx441, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx13394.data[0][0], 0, sizeof(bmats.Bx13394.data[0][0])*bmats.Bx13394.shape[0]*bmats.Bx13394.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13394, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
