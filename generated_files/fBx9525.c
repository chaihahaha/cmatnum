#include "stdafx.h"
#include "fBx9525.h"

inline int fBx9525(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_25_1, bmats.B_25_2, bmats.B_25_3, bmats.B_25_4, bmats.B_25_5, bmats.B_25_6, bmats.B_25_7, bmats.B_25_8, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx9525.data[0][0], 0, sizeof(bmats.Bx9525.data[0][0])*bmats.Bx9525.shape[0]*bmats.Bx9525.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9525, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
