#include "stdafx.h"
#include "fBx12968.h"

inline int fBx12968(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_1_8, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx12968.data[0][0], 0, sizeof(bmats.Bx12968.data[0][0])*bmats.Bx12968.shape[0]*bmats.Bx12968.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12968, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
