#include "stdafx.h"
#include "fBx11833.h"

inline int fBx11833(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx11450, bmats.Bx11452, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx11833.data[0][0], 0, sizeof(bmats.Bx11833.data[0][0])*bmats.Bx11833.shape[0]*bmats.Bx11833.shape[1]);
    matlincomb_double_contiguous(bmats.Bx11833, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
