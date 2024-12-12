#include "stdafx.h"
#include "fBx1809.h"

inline int fBx1809(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_14, bmats.B_4_19, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx1809.data[0][0], 0, sizeof(bmats.Bx1809.data[0][0])*bmats.Bx1809.shape[0]*bmats.Bx1809.shape[1]);
    matlincomb_double_contiguous(bmats.Bx1809, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
