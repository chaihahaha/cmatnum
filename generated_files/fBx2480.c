#include "stdafx.h"
#include "fBx2480.h"

inline int fBx2480(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_30_17, bmats.B_30_25, bmats.B_30_26, bmats.B_30_27, bmats.B_30_28, bmats.Bx744, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx2480.data[0][0], 0, sizeof(bmats.Bx2480.data[0][0])*bmats.Bx2480.shape[0]*bmats.Bx2480.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2480, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
