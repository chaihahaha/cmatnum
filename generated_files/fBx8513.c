#include "stdafx.h"
#include "fBx8513.h"

inline int fBx8513(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 1;
    double_cmat B_mats[1] = {bmats.B_25_27, };
    double B_coeffs[1] = {-1, };
memset(&bmats.Bx8513.data[0][0], 0, sizeof(bmats.Bx8513.data[0][0])*bmats.Bx8513.shape[0]*bmats.Bx8513.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8513, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
