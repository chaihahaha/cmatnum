#include "stdafx.h"
#include "fBx836.h"

inline int fBx836(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_31_17, bmats.B_31_18, bmats.B_31_19, bmats.B_31_31, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx836.data[0][0], 0, sizeof(bmats.Bx836.data[0][0])*bmats.Bx836.shape[0]*bmats.Bx836.shape[1]);
    matlincomb_double_contiguous(bmats.Bx836, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
