#include "stdafx.h"
#include "fAxxeval3515.h"

inline int fAxxeval3515(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2443.data[0][0], 0, sizeof(bmats.Axx2443.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_19_2, };
    double A_coeffs[1] = {16, };
    matlincomb_double_contiguous(bmats.Axx2443, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
