#include "stdafx.h"
#include "fAxxeval4637.h"

inline int fAxxeval4637(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3354.data[0][0], 0, sizeof(bmats.Axx3354.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_32_5, bmats.Axx3353, bmats.Axx989, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx3354, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}