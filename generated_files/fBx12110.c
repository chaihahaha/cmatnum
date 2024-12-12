#include "stdafx.h"
#include "fBx12110.h"

inline int fBx12110(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_25_10, bmats.B_25_11, bmats.Bx12109, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12110.data[0][0], 0, sizeof(bmats.Bx12110.data[0][0])*bmats.Bx12110.shape[0]*bmats.Bx12110.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12110, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
