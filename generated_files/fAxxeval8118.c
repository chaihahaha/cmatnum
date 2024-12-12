#include "stdafx.h"
#include "fAxxeval8118.h"

inline int fAxxeval8118(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3073.data[0][0], 0, sizeof(bmats.Axx3073.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx3095, bmats.Axx3191, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx3073, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
