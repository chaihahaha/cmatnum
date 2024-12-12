#include "stdafx.h"
#include "fAxxeval7515.h"

inline int fAxxeval7515(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx877.data[0][0], 0, sizeof(bmats.Axx877.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_26_25, bmats.Axx11, bmats.Axx3238, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx877, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
