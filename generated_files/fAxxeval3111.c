#include "stdafx.h"
#include "fAxxeval3111.h"

inline int fAxxeval3111(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx901.data[0][0], 0, sizeof(bmats.Axx901.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_32_24, };
    double A_coeffs[1] = {2, };
    matlincomb_double_contiguous(bmats.Axx901, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}