#include "stdafx.h"
#include "fBx9716.h"

inline int fBx9716(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_24_22, bmats.B_24_32, bmats.Bx1463, bmats.Bx7505, bmats.Bx8938, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx9716.data[0][0], 0, sizeof(bmats.Bx9716.data[0][0])*bmats.Bx9716.shape[0]*bmats.Bx9716.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9716, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
