#include "stdafx.h"
#include "fBx12958.h"

inline int fBx12958(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_11_1, bmats.B_2_1, bmats.Bx12913, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12958.data[0][0], 0, sizeof(bmats.Bx12958.data[0][0])*bmats.Bx12958.shape[0]*bmats.Bx12958.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12958, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}