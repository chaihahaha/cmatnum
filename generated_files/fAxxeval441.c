#include "stdafx.h"
#include "fAxxeval441.h"

inline int fAxxeval441(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx442.data[0][0], 0, sizeof(bmats.Axx442.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_6_16, };
    double A_coeffs[1] = {16, };
    matlincomb_double_contiguous(bmats.Axx442, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
