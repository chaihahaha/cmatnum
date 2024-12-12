#include "stdafx.h"
#include "fBx11087.h"

inline int fBx11087(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_25_18, bmats.B_25_19, bmats.Bx4680, bmats.Bx9759, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx11087.data[0][0], 0, sizeof(bmats.Bx11087.data[0][0])*bmats.Bx11087.shape[0]*bmats.Bx11087.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11087, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
