#include "stdafx.h"
#include "fBx12250.h"

inline int fBx12250(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_21_1, bmats.B_21_2, bmats.B_21_3, bmats.B_21_4, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12250.data[0][0], 0, sizeof(bmats.Bx12250.data[0][0])*bmats.Bx12250.shape[0]*bmats.Bx12250.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12250, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
