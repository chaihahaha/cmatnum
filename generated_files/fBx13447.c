#include "stdafx.h"
#include "fBx13447.h"

inline int fBx13447(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_9_16, bmats.Bx13363, bmats.Bx13377, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx13447.data[0][0], 0, sizeof(bmats.Bx13447.data[0][0])*bmats.Bx13447.shape[0]*bmats.Bx13447.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13447, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}