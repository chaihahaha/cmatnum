#include "stdafx.h"
#include "fAxxeval4642.h"

inline int fAxxeval4642(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3358.data[0][0], 0, sizeof(bmats.Axx3358.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_32_7, bmats.Axx3314, bmats.Axx3357, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3358, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
