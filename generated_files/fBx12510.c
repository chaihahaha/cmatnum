#include "stdafx.h"
#include "fBx12510.h"

inline int fBx12510(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12509, bmats.Bx1463, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12510.data[0][0], 0, sizeof(bmats.Bx12510.data[0][0])*bmats.Bx12510.shape[0]*bmats.Bx12510.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12510, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
