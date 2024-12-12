#include "stdafx.h"
#include "fBx704.h"

inline int fBx704(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_30, bmats.B_30_23, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx704.data[0][0], 0, sizeof(bmats.Bx704.data[0][0])*bmats.Bx704.shape[0]*bmats.Bx704.shape[1]);
    matlincomb_double_contiguous(bmats.Bx704, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
