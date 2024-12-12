#include "stdafx.h"
#include "fBx12974.h"

inline int fBx12974(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.B_25_32, bmats.Bx4680, bmats.Bx9758, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx12974.data[0][0], 0, sizeof(bmats.Bx12974.data[0][0])*bmats.Bx12974.shape[0]*bmats.Bx12974.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12974, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
