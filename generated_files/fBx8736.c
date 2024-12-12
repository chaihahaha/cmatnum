#include "stdafx.h"
#include "fBx8736.h"

inline int fBx8736(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_32_9, bmats.B_5_32, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx8736.data[0][0], 0, sizeof(bmats.Bx8736.data[0][0])*bmats.Bx8736.shape[0]*bmats.Bx8736.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8736, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
