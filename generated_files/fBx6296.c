#include "stdafx.h"
#include "fBx6296.h"

inline int fBx6296(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 12;
    double_cmat B_mats[12] = {bmats.B_12_17, bmats.B_12_18, bmats.B_12_19, bmats.B_12_20, bmats.B_12_21, bmats.B_12_22, bmats.B_12_23, bmats.B_12_24, bmats.B_12_25, bmats.B_12_26, bmats.B_12_27, bmats.Bx4580, };
    double B_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx6296.data[0][0], 0, sizeof(bmats.Bx6296.data[0][0])*bmats.Bx6296.shape[0]*bmats.Bx6296.shape[1]);
    matlincomb_double_contiguous(bmats.Bx6296, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
