#include "stdafx.h"
#include "fBx4615.h"

inline int fBx4615(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_13_10, bmats.B_13_3, bmats.B_13_4, bmats.B_13_6, bmats.B_13_7, bmats.B_13_8, bmats.Bx1306, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx4615.data[0][0], 0, sizeof(bmats.Bx4615.data[0][0])*bmats.Bx4615.shape[0]*bmats.Bx4615.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4615, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
