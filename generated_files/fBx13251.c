#include "stdafx.h"
#include "fBx13251.h"

inline int fBx13251(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 16;
    double_cmat B_mats[16] = {bmats.Bx10835, bmats.Bx11350, bmats.Bx11778, bmats.Bx12163, bmats.Bx12638, bmats.Bx12855, bmats.Bx13019, bmats.Bx13250, bmats.Bx2361, bmats.Bx3967, bmats.Bx5327, bmats.Bx600, bmats.Bx7127, bmats.Bx8137, bmats.Bx9025, bmats.Bx9778, };
    double B_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13251.data[0][0], 0, sizeof(bmats.Bx13251.data[0][0])*bmats.Bx13251.shape[0]*bmats.Bx13251.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13251, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
