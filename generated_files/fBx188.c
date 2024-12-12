#include "stdafx.h"
#include "fBx188.h"

inline int fBx188(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 2;
    double_cmat B_mats[2] = {bmats.B_23_24, bmats.B_24_23, };
    double B_coeffs[2] = {1, 1, };
memset(&bmats.Bx188.data[0][0], 0, sizeof(bmats.Bx188.data[0][0])*bmats.Bx188.shape[0]*bmats.Bx188.shape[1]);
    matlincomb_double_contiguous(bmats.Bx188, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
