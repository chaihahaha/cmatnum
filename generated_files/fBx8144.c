#include "stdafx.h"
#include "fBx8144.h"

inline int fBx8144(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_24, bmats.B_8_26, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8144.data[0][0], 0, sizeof(bmats.Bx8144.data[0][0])*bmats.Bx8144.shape[0]*bmats.Bx8144.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8144, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
