#include "stdafx.h"
#include "fBx12112.h"

inline int fBx12112(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_15_20, bmats.B_16_20, bmats.B_6_20, bmats.Bx12054, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12112.data[0][0], 0, sizeof(bmats.Bx12112.data[0][0])*bmats.Bx12112.shape[0]*bmats.Bx12112.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12112, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
