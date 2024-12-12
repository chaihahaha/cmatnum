#include "stdafx.h"
#include "fBx12495.h"

inline int fBx12495(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_6_3, bmats.B_8_3, bmats.Bx12418, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12495.data[0][0], 0, sizeof(bmats.Bx12495.data[0][0])*bmats.Bx12495.shape[0]*bmats.Bx12495.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12495, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
