#include "stdafx.h"
#include "fBx7947.h"

inline int fBx7947(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_10, bmats.B_7_16, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7947.data[0][0], 0, sizeof(bmats.Bx7947.data[0][0])*bmats.Bx7947.shape[0]*bmats.Bx7947.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7947, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}