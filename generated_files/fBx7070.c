#include "stdafx.h"
#include "fBx7070.h"

inline int fBx7070(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_15_27, bmats.B_18_15, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7070.data[0][0], 0, sizeof(bmats.Bx7070.data[0][0])*bmats.Bx7070.shape[0]*bmats.Bx7070.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7070, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
