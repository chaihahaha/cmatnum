#include "stdafx.h"
#include "fBx9458.h"

inline int fBx9458(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_22_24, bmats.B_23_24, bmats.B_32_24, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9458.data[0][0], 0, sizeof(bmats.Bx9458.data[0][0])*bmats.Bx9458.shape[0]*bmats.Bx9458.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9458, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
