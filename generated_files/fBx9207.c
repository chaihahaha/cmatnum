#include "stdafx.h"
#include "fBx9207.h"

inline int fBx9207(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_17_24, bmats.B_18_24, bmats.B_19_24, bmats.Bx9206, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx9207.data[0][0], 0, sizeof(bmats.Bx9207.data[0][0])*bmats.Bx9207.shape[0]*bmats.Bx9207.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9207, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
