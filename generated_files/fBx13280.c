#include "stdafx.h"
#include "fBx13280.h"

inline int fBx13280(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10445, bmats.Bx11078, bmats.Bx11641, bmats.Bx12150, bmats.Bx12512, bmats.Bx12773, bmats.Bx13008, bmats.Bx13278, bmats.Bx13279, bmats.Bx1495, bmats.Bx3118, bmats.Bx5211, bmats.Bx6436, bmats.Bx7519, bmats.Bx8549, bmats.Bx9470, bmats.Bx9710, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13280.data[0][0], 0, sizeof(bmats.Bx13280.data[0][0])*bmats.Bx13280.shape[0]*bmats.Bx13280.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13280, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
