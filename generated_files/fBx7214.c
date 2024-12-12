#include "stdafx.h"
#include "fBx7214.h"

inline int fBx7214(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_20_26, bmats.B_21_26, bmats.B_22_26, bmats.Bx7212, bmats.Bx7213, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx7214.data[0][0], 0, sizeof(bmats.Bx7214.data[0][0])*bmats.Bx7214.shape[0]*bmats.Bx7214.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7214, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
