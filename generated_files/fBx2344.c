#include "stdafx.h"
#include "fBx2344.h"

inline int fBx2344(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_3_14, bmats.Bx2343, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2344.data[0][0], 0, sizeof(bmats.Bx2344.data[0][0])*bmats.Bx2344.shape[0]*bmats.Bx2344.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2344, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
