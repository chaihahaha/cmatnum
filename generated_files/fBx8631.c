#include "stdafx.h"
#include "fBx8631.h"

inline int fBx8631(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_9_25, bmats.B_9_31, bmats.Bx7640, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx8631.data[0][0], 0, sizeof(bmats.Bx8631.data[0][0])*bmats.Bx8631.shape[0]*bmats.Bx8631.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8631, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
