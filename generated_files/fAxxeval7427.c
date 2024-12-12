#include "stdafx.h"
#include "fAxxeval7427.h"

inline int fAxxeval7427(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2718.data[0][0], 0, sizeof(bmats.Axx2718.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_18_30, bmats.Axx194, bmats.Axx2531, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2718, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
