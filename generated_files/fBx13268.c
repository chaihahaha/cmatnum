#include "stdafx.h"
#include "fBx13268.h"

inline int fBx13268(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10619, bmats.Bx10915, bmats.Bx11201, bmats.Bx11708, bmats.Bx12130, bmats.Bx12552, bmats.Bx12798, bmats.Bx12999, bmats.Bx13266, bmats.Bx13267, bmats.Bx1998, bmats.Bx3604, bmats.Bx5005, bmats.Bx6818, bmats.Bx7872, bmats.Bx8773, bmats.Bx9563, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13268.data[0][0], 0, sizeof(bmats.Bx13268.data[0][0])*bmats.Bx13268.shape[0]*bmats.Bx13268.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13268, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
