#include "stdafx.h"
#include "fBx12487.h"

inline int fBx12487(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_19_28, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx12487.data[0][0], 0, sizeof(bmats.Bx12487.data[0][0])*bmats.Bx12487.shape[0]*bmats.Bx12487.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12487, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}