#include "stdafx.h"
#include "fBx7688.h"

inline int fBx7688(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_10_7, bmats.Bx1719, bmats.Bx7687, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7688.data[0][0], 0, sizeof(bmats.Bx7688.data[0][0])*bmats.Bx7688.shape[0]*bmats.Bx7688.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7688, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
