#include "stdafx.h"
#include "fBx12142.h"

inline int fBx12142(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 8;
    double_cmat B_mats[8] = {bmats.B_10_20, bmats.B_13_20, bmats.B_14_20, bmats.B_5_20, bmats.B_7_20, bmats.B_8_20, bmats.B_9_20, bmats.Bx12112, };
    double B_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12142.data[0][0], 0, sizeof(bmats.Bx12142.data[0][0])*bmats.Bx12142.shape[0]*bmats.Bx12142.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12142, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
