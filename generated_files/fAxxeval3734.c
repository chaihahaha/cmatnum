#include "stdafx.h"
#include "fAxxeval3734.h"

inline int fAxxeval3734(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2633.data[0][0], 0, sizeof(bmats.Axx2633.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_26_11, bmats.Axx2589, bmats.Axx2632, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2633, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}