#include "stdafx.h"
#include "fBx12948.h"

inline int fBx12948(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_8_1, bmats.Bx12947, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12948.data[0][0], 0, sizeof(bmats.Bx12948.data[0][0])*bmats.Bx12948.shape[0]*bmats.Bx12948.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12948, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
