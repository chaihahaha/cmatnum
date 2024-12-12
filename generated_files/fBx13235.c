#include "stdafx.h"
#include "fBx13235.h"

inline int fBx13235(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10010, bmats.Bx10991, bmats.Bx11523, bmats.Bx11946, bmats.Bx12265, bmats.Bx12719, bmats.Bx12905, bmats.Bx13229, bmats.Bx13230, bmats.Bx13234, bmats.Bx234, bmats.Bx2666, bmats.Bx4312, bmats.Bx5666, bmats.Bx7339, bmats.Bx8401, bmats.Bx9285, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13235.data[0][0], 0, sizeof(bmats.Bx13235.data[0][0])*bmats.Bx13235.shape[0]*bmats.Bx13235.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13235, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
