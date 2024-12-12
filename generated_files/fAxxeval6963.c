#include "stdafx.h"
#include "fAxxeval6963.h"

inline int fAxxeval6963(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3205.data[0][0], 0, sizeof(bmats.Axx3205.data[0][0])*BL*BL);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1072, bmats.Axx1164, bmats.Axx216, bmats.Axx3370, };
    double A_coeffs[4] = {1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3205, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
