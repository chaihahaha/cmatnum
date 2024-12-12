#include "stdafx.h"
#include "fBx13298.h"

inline int fBx13298(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10348, bmats.Bx11042, bmats.Bx1108, bmats.Bx11607, bmats.Bx12127, bmats.Bx12480, bmats.Bx12746, bmats.Bx12986, bmats.Bx13296, bmats.Bx13297, bmats.Bx2797, bmats.Bx4899, bmats.Bx5980, bmats.Bx6217, bmats.Bx7424, bmats.Bx8511, bmats.Bx9549, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13298.data[0][0], 0, sizeof(bmats.Bx13298.data[0][0])*bmats.Bx13298.shape[0]*bmats.Bx13298.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13298, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
