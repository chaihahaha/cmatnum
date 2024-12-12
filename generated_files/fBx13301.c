#include "stdafx.h"
#include "fBx13301.h"

inline int fBx13301(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10342, bmats.Bx1061, bmats.Bx11033, bmats.Bx11609, bmats.Bx12124, bmats.Bx12477, bmats.Bx12740, bmats.Bx12942, bmats.Bx13299, bmats.Bx13300, bmats.Bx2859, bmats.Bx4879, bmats.Bx5976, bmats.Bx6264, bmats.Bx7411, bmats.Bx8513, bmats.Bx9547, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13301.data[0][0], 0, sizeof(bmats.Bx13301.data[0][0])*bmats.Bx13301.shape[0]*bmats.Bx13301.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13301, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
