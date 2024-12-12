#include "stdafx.h"
#include "fBx12088.h"

inline int fBx12088(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_20_20, bmats.B_24_20, bmats.B_25_20, bmats.B_26_20, bmats.Bx11896, bmats.Bx12087, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12088.data[0][0], 0, sizeof(bmats.Bx12088.data[0][0])*bmats.Bx12088.shape[0]*bmats.Bx12088.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12088, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
