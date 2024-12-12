#include "stdafx.h"
#include "fAxxeval3812.h"

inline int fAxxeval3812(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2703.data[0][0], 0, sizeof(bmats.Axx2703.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_25_9, bmats.Axx2661, bmats.Axx2702, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2703, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
