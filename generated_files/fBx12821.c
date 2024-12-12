#include "stdafx.h"
#include "fBx12821.h"

inline int fBx12821(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.Bx12820, bmats.Bx5852, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx12821.data[0][0], 0, sizeof(bmats.Bx12821.data[0][0])*bmats.Bx12821.shape[0]*bmats.Bx12821.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12821, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
