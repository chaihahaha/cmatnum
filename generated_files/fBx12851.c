#include "stdafx.h"
#include "fBx12851.h"

inline int fBx12851(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_2_3, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx12851.data[0][0], 0, sizeof(bmats.Bx12851.data[0][0])*bmats.Bx12851.shape[0]*bmats.Bx12851.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12851, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
