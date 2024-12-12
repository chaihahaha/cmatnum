#include "stdafx.h"
#include "fBx12277.h"

inline int fBx12277(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_3, bmats.Bx11959, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12277.data[0][0], 0, sizeof(bmats.Bx12277.data[0][0])*bmats.Bx12277.shape[0]*bmats.Bx12277.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12277, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
