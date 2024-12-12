#include "stdafx.h"
#include "fBx12522.h"

inline int fBx12522(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_13_3, bmats.B_3_3, bmats.Bx12495, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12522.data[0][0], 0, sizeof(bmats.Bx12522.data[0][0])*bmats.Bx12522.shape[0]*bmats.Bx12522.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12522, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
