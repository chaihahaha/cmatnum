#include "stdafx.h"
#include "fBx9758.h"

inline int fBx9758(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_25_18, bmats.B_25_19, bmats.B_25_20, bmats.B_25_22, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9758.data[0][0], 0, sizeof(bmats.Bx9758.data[0][0])*bmats.Bx9758.shape[0]*bmats.Bx9758.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9758, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
