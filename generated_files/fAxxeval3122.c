#include "stdafx.h"
#include "fAxxeval3122.h"

inline int fAxxeval3122(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx641.data[0][0], 0, sizeof(bmats.Axx641.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_32_18, bmats.Axx523, bmats.Axx898, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx641, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
