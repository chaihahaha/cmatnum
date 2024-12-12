#include "stdafx.h"
#include "fBx7428.h"

inline int fBx7428(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx6236, bmats.Bx7427, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7428.data[0][0], 0, sizeof(bmats.Bx7428.data[0][0])*bmats.Bx7428.shape[0]*bmats.Bx7428.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7428, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
