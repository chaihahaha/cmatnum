#include "stdafx.h"
#include "fBx7212.h"

inline int fBx7212(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_17_26, bmats.B_18_26, bmats.B_19_26, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7212.data[0][0], 0, sizeof(bmats.Bx7212.data[0][0])*bmats.Bx7212.shape[0]*bmats.Bx7212.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7212, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
