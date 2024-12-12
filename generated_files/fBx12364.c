#include "stdafx.h"
#include "fBx12364.h"

inline int fBx12364(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx10169, bmats.Bx12044, bmats.Bx9433, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12364.data[0][0], 0, sizeof(bmats.Bx12364.data[0][0])*bmats.Bx12364.shape[0]*bmats.Bx12364.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12364, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
