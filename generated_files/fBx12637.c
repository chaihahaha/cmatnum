#include "stdafx.h"
#include "fBx12637.h"

inline int fBx12637(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_3_17, bmats.B_3_18, bmats.B_3_19, bmats.B_3_31, bmats.B_3_32, bmats.Bx12180, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12637.data[0][0], 0, sizeof(bmats.Bx12637.data[0][0])*bmats.Bx12637.shape[0]*bmats.Bx12637.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12637, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
