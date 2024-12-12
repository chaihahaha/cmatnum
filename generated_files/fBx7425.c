#include "stdafx.h"
#include "fBx7425.h"

inline int fBx7425(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_27_19, bmats.B_27_20, bmats.B_27_21, bmats.B_27_22, bmats.B_27_24, bmats.Bx6226, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx7425.data[0][0], 0, sizeof(bmats.Bx7425.data[0][0])*bmats.Bx7425.shape[0]*bmats.Bx7425.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7425, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
