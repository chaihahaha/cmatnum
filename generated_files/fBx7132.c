#include "stdafx.h"
#include "fBx7132.h"

inline int fBx7132(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_17, bmats.B_1_27, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx7132.data[0][0], 0, sizeof(bmats.Bx7132.data[0][0])*bmats.Bx7132.shape[0]*bmats.Bx7132.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7132, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}