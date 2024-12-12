#include "stdafx.h"
#include "fBx7759.h"

inline int fBx7759(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_10, bmats.B_5_1, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7759.data[0][0], 0, sizeof(bmats.Bx7759.data[0][0])*bmats.Bx7759.shape[0]*bmats.Bx7759.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7759, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
