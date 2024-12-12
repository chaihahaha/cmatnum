#include "stdafx.h"
#include "fBx8251.h"

inline int fBx8251(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_25_25, bmats.B_26_25, bmats.B_27_25, bmats.B_29_25, bmats.B_30_25, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx8251.data[0][0], 0, sizeof(bmats.Bx8251.data[0][0])*bmats.Bx8251.shape[0]*bmats.Bx8251.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8251, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
