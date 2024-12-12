#include "stdafx.h"
#include "fBx8686.h"

inline int fBx8686(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_11_10, bmats.B_11_7, bmats.Bx7405, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx8686.data[0][0], 0, sizeof(bmats.Bx8686.data[0][0])*bmats.Bx8686.shape[0]*bmats.Bx8686.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8686, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
