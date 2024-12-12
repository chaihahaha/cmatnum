#include "stdafx.h"
#include "fBx12636.h"

inline int fBx12636(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 6;
    double_cmat B_mats[6] = {bmats.B_19_1, bmats.B_19_15, bmats.B_19_16, bmats.B_19_2, bmats.B_19_3, bmats.Bx12174, };
    double B_coeffs[6] = {1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx12636.data[0][0], 0, sizeof(bmats.Bx12636.data[0][0])*bmats.Bx12636.shape[0]*bmats.Bx12636.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12636, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
