#include "stdafx.h"
#include "fBx2092.h"

inline int fBx2092(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_25_14, bmats.B_7_9, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2092.data[0][0], 0, sizeof(bmats.Bx2092.data[0][0])*bmats.Bx2092.shape[0]*bmats.Bx2092.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2092, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
