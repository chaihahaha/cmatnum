#include "stdafx.h"
#include "fBx9995.h"

inline int fBx9995(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_26_23, bmats.B_30_23, bmats.B_31_23, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx9995.data[0][0], 0, sizeof(bmats.Bx9995.data[0][0])*bmats.Bx9995.shape[0]*bmats.Bx9995.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9995, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
