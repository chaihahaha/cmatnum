#include "stdafx.h"
#include "fBx8532.h"

inline int fBx8532(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_25_25, bmats.B_27_25, bmats.Bx8519, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx8532.data[0][0], 0, sizeof(bmats.Bx8532.data[0][0])*bmats.Bx8532.shape[0]*bmats.Bx8532.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8532, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
