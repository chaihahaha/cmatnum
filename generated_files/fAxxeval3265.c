#include "stdafx.h"
#include "fAxxeval3265.h"

inline int fAxxeval3265(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2225.data[0][0], 0, sizeof(bmats.Axx2225.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_17_7, bmats.Axx2184, bmats.Axx2224, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2225, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
