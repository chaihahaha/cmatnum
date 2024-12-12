#include "stdafx.h"
#include "fBx12213.h"

inline int fBx12213(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 4;
    double_cmat B_mats[4] = {bmats.B_20_19, bmats.B_20_32, bmats.Bx11841, bmats.Bx2449, };
    double B_coeffs[4] = {1, 1, 1, 1, };
memset(&bmats.Bx12213.data[0][0], 0, sizeof(bmats.Bx12213.data[0][0])*bmats.Bx12213.shape[0]*bmats.Bx12213.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12213, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
