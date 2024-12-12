#include "stdafx.h"
#include "fBx2487.h"

inline int fBx2487(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_11_29, bmats.B_12_29, bmats.Bx2486, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx2487.data[0][0], 0, sizeof(bmats.Bx2487.data[0][0])*bmats.Bx2487.shape[0]*bmats.Bx2487.shape[1]);
    matlincomb_double_contiguous(bmats.Bx2487, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
