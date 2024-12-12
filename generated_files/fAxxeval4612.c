#include "stdafx.h"
#include "fAxxeval4612.h"

inline int fAxxeval4612(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3332.data[0][0], 0, sizeof(bmats.Axx3332.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_32_9, };
    double A_coeffs[1] = {-1, };
    matlincomb_double_contiguous(bmats.Axx3332, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
