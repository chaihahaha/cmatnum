#include "stdafx.h"
#include "fBx12469.h"

inline int fBx12469(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_26_15, bmats.B_26_16, bmats.B_26_8, bmats.B_26_9, bmats.Bx8679, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12469.data[0][0], 0, sizeof(bmats.Bx12469.data[0][0])*bmats.Bx12469.shape[0]*bmats.Bx12469.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12469, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
