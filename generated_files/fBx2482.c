#include "stdafx.h"
#include "fBx2482.h"

inline int fBx2482(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_30_22, bmats.Bx2481, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2482.data[0][0], 0, sizeof(bmats.Bx2482.data[0][0])*bmats.Bx2482.shape[0]*bmats.Bx2482.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2482, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
