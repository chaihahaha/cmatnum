#include "stdafx.h"
#include "fAxxeval3353.h"

inline int fAxxeval3353(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2301.data[0][0], 0, sizeof(bmats.Axx2301.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_22_16, bmats.Axx2265, bmats.Axx2300, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2301, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
