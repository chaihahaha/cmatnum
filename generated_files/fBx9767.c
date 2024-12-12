#include "stdafx.h"
#include "fBx9767.h"

inline int fBx9767(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_19_23, bmats.B_23_24, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx9767.data[0][0], 0, sizeof(bmats.Bx9767.data[0][0])*bmats.Bx9767.shape[0]*bmats.Bx9767.shape[1]);
    matlincomb_double_contiguous(bmats.Bx9767, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
