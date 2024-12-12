#include "stdafx.h"
#include "fBx8612.h"

inline int fBx8612(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_25_26, bmats.B_25_31, bmats.B_25_32, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx8612.data[0][0], 0, sizeof(bmats.Bx8612.data[0][0])*bmats.Bx8612.shape[0]*bmats.Bx8612.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8612, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
