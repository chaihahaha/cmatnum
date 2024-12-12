#include "stdafx.h"
#include "fBx837.h"

inline int fBx837(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_17_30, bmats.B_18_30, bmats.B_19_30, bmats.B_30_30, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx837.data[0][0], 0, sizeof(bmats.Bx837.data[0][0])*bmats.Bx837.shape[0]*bmats.Bx837.shape[1]);
    matlincomb_double_contiguous(bmats.Bx837, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
