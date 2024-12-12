#include "stdafx.h"
#include "fBx9777.h"

inline int fBx9777(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx9244, bmats.Bx9282, bmats.Bx9451, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9777.data[0][0], 0, sizeof(bmats.Bx9777.data[0][0])*bmats.Bx9777.shape[0]*bmats.Bx9777.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9777, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
