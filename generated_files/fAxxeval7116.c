#include "stdafx.h"
#include "fAxxeval7116.h"

inline int fAxxeval7116(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3247.data[0][0], 0, sizeof(bmats.Axx3247.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_20_22, bmats.Axx587, bmats.Axx616, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3247, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
