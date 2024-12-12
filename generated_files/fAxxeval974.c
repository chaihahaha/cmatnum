#include "stdafx.h"
#include "fAxxeval974.h"

inline int fAxxeval974(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx975.data[0][0], 0, sizeof(bmats.Axx975.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_29_16, };
    double A_coeffs[1] = {-1, };
    matlincomb_double_contiguous(bmats.Axx975, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
