#include "stdafx.h"
#include "fBx12544.h"

inline int fBx12544(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_25_19, bmats.Bx12501, bmats.Bx12515, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12544.data[0][0], 0, sizeof(bmats.Bx12544.data[0][0])*bmats.Bx12544.shape[0]*bmats.Bx12544.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12544, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
