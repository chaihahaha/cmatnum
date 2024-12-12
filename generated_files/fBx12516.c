#include "stdafx.h"
#include "fBx12516.h"

inline int fBx12516(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_25_20, bmats.Bx4680, bmats.Bx9759, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12516.data[0][0], 0, sizeof(bmats.Bx12516.data[0][0])*bmats.Bx12516.shape[0]*bmats.Bx12516.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12516, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
