#include "stdafx.h"
#include "fAxxeval4573.h"

inline int fAxxeval4573(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx985.data[0][0], 0, sizeof(bmats.Axx985.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx3279, bmats.Axx989, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx985, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
