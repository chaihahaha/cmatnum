#include "stdafx.h"
#include "fBx9477.h"

inline int fBx9477(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_14_8, bmats.Bx9467, bmats.Bx9476, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9477.data[0][0], 0, sizeof(bmats.Bx9477.data[0][0])*bmats.Bx9477.shape[0]*bmats.Bx9477.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9477, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
