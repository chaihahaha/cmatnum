#include "stdafx.h"
#include "fBx13245.h"

inline int fBx13245(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10079, bmats.Bx10685, bmats.Bx11259, bmats.Bx11984, bmats.Bx12309, bmats.Bx12558, bmats.Bx12806, bmats.Bx12863, bmats.Bx13060, bmats.Bx13244, bmats.Bx2165, bmats.Bx300, bmats.Bx4396, bmats.Bx5746, bmats.Bx6909, bmats.Bx8005, bmats.Bx9349, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13245.data[0][0], 0, sizeof(bmats.Bx13245.data[0][0])*bmats.Bx13245.shape[0]*bmats.Bx13245.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13245, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
