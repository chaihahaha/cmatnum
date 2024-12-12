#include "stdafx.h"
#include "fBx9538.h"

inline int fBx9538(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_26_25, bmats.B_26_31, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9538.data[0][0], 0, sizeof(bmats.Bx9538.data[0][0])*bmats.Bx9538.shape[0]*bmats.Bx9538.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9538, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
