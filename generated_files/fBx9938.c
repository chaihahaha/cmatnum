#include "stdafx.h"
#include "fBx9938.h"

inline int fBx9938(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_21_7, bmats.B_23_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9938.data[0][0], 0, sizeof(bmats.Bx9938.data[0][0])*bmats.Bx9938.shape[0]*bmats.Bx9938.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9938, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
