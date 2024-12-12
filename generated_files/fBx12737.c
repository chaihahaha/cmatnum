#include "stdafx.h"
#include "fBx12737.h"

inline int fBx12737(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_13_2, bmats.B_14_2, bmats.B_2_2, bmats.B_9_2, bmats.Bx12701, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12737.data[0][0], 0, sizeof(bmats.Bx12737.data[0][0])*bmats.Bx12737.shape[0]*bmats.Bx12737.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12737, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
