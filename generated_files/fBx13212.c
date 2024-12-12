#include "stdafx.h"
#include "fBx13212.h"

inline int fBx13212(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 27;
    double_cmat B_mats[27] = {bmats.B_11_14, bmats.B_12_14, bmats.B_13_14, bmats.B_15_14, bmats.B_2_14, bmats.B_4_14, bmats.B_5_14, bmats.B_6_14, bmats.Bx10265, bmats.Bx10904, bmats.Bx11432, bmats.Bx12091, bmats.Bx12431, bmats.Bx12671, bmats.Bx12967, bmats.Bx1307, bmats.Bx13210, bmats.Bx13211, bmats.Bx2479, bmats.Bx4655, bmats.Bx5994, bmats.Bx7217, bmats.Bx730, bmats.Bx823, bmats.Bx8258, bmats.Bx935, bmats.Bx9495, };
    double B_coeffs[27] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13212.data[0][0], 0, sizeof(bmats.Bx13212.data[0][0])*bmats.Bx13212.shape[0]*bmats.Bx13212.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13212, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
