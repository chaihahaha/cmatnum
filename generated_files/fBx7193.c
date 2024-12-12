#include "stdafx.h"
#include "fBx7193.h"

inline int fBx7193(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_20_10, bmats.Bx7186, bmats.Bx7187, bmats.Bx7188, bmats.Bx7189, bmats.Bx7192, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx7193.data[0][0], 0, sizeof(bmats.Bx7193.data[0][0])*bmats.Bx7193.shape[0]*bmats.Bx7193.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7193, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
