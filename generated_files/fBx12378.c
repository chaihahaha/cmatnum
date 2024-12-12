#include "stdafx.h"
#include "fBx12378.h"

inline int fBx12378(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_1_4, bmats.B_2_17, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12378.data[0][0], 0, sizeof(bmats.Bx12378.data[0][0])*bmats.Bx12378.shape[0]*bmats.Bx12378.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12378, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
