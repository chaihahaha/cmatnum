#include "stdafx.h"
#include "fAxxeval7886.h"

inline int fAxxeval7886(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx285.data[0][0], 0, sizeof(bmats.Axx285.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx104, bmats.Axx884, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx285, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}