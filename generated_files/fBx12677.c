#include "stdafx.h"
#include "fBx12677.h"

inline int fBx12677(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12665, bmats.Bx12676, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12677.data[0][0], 0, sizeof(bmats.Bx12677.data[0][0])*bmats.Bx12677.shape[0]*bmats.Bx12677.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12677, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
