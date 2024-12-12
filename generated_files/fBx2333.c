#include "stdafx.h"
#include "fBx2333.h"

inline int fBx2333(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_27_14, bmats.B_3_11, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx2333.data[0][0], 0, sizeof(bmats.Bx2333.data[0][0])*bmats.Bx2333.shape[0]*bmats.Bx2333.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2333, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
