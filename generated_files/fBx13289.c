#include "stdafx.h"
#include "fBx13289.h"

inline int fBx13289(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10452, bmats.Bx11086, bmats.Bx11648, bmats.Bx12113, bmats.Bx12514, bmats.Bx12775, bmats.Bx12973, bmats.Bx13287, bmats.Bx13288, bmats.Bx1571, bmats.Bx3213, bmats.Bx4675, bmats.Bx6082, bmats.Bx7590, bmats.Bx8279, bmats.Bx8649, bmats.Bx9529, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13289.data[0][0], 0, sizeof(bmats.Bx13289.data[0][0])*bmats.Bx13289.shape[0]*bmats.Bx13289.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13289, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
