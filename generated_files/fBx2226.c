#include "stdafx.h"
#include "fBx2226.h"

inline int fBx2226(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_30_2, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx2226.data[0][0], 0, sizeof(bmats.Bx2226.data[0][0])*bmats.Bx2226.shape[0]*bmats.Bx2226.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2226, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
