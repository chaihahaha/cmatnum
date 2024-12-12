#include "stdafx.h"
#include "fBx9201.h"

inline int fBx9201(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_22_24, bmats.B_31_6, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9201.data[0][0], 0, sizeof(bmats.Bx9201.data[0][0])*bmats.Bx9201.shape[0]*bmats.Bx9201.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9201, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
