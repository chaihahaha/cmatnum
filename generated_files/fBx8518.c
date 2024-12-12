#include "stdafx.h"
#include "fBx8518.h"

inline int fBx8518(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_25_25, bmats.B_29_25, bmats.B_30_25, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx8518.data[0][0], 0, sizeof(bmats.Bx8518.data[0][0])*bmats.Bx8518.shape[0]*bmats.Bx8518.shape[1]);
    matlincomb_double_contiguous(bmats.Bx8518, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
