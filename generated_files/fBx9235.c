#include "stdafx.h"
#include "fBx9235.h"

inline int fBx9235(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_24_31, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx9235.data[0][0], 0, sizeof(bmats.Bx9235.data[0][0])*bmats.Bx9235.shape[0]*bmats.Bx9235.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9235, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
