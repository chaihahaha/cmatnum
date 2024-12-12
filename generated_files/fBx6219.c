#include "stdafx.h"
#include "fBx6219.h"

inline int fBx6219(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_27_19, bmats.B_3_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx6219.data[0][0], 0, sizeof(bmats.Bx6219.data[0][0])*bmats.Bx6219.shape[0]*bmats.Bx6219.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6219, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
