#include "stdafx.h"
#include "fBx13408.h"

inline int fBx13408(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_23_17, bmats.B_23_22, bmats.B_23_24, bmats.Bx11239, bmats.Bx5095, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx13408.data[0][0], 0, sizeof(bmats.Bx13408.data[0][0])*bmats.Bx13408.shape[0]*bmats.Bx13408.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13408, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
