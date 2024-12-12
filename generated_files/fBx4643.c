#include "stdafx.h"
#include "fBx4643.h"

inline int fBx4643(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx4243, bmats.Bx4620, bmats.Bx4642, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx4643.data[0][0], 0, sizeof(bmats.Bx4643.data[0][0])*bmats.Bx4643.shape[0]*bmats.Bx4643.shape[1]);
    matlincomb_double_contiguous(bmats.Bx4643, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
