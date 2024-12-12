#include "stdafx.h"
#include "fBx12442.h"

inline int fBx12442(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12283, bmats.Bx12411, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12442.data[0][0], 0, sizeof(bmats.Bx12442.data[0][0])*bmats.Bx12442.shape[0]*bmats.Bx12442.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12442, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
