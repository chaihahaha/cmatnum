#include "stdafx.h"
#include "fBx12953.h"

inline int fBx12953(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_17, bmats.Bx12879, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12953.data[0][0], 0, sizeof(bmats.Bx12953.data[0][0])*bmats.Bx12953.shape[0]*bmats.Bx12953.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12953, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
