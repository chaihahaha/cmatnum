#include "stdafx.h"
#include "fAxxeval3729.h"

inline int fAxxeval3729(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2629.data[0][0], 0, sizeof(bmats.Axx2629.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_26_9, bmats.Axx2585, bmats.Axx2628, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2629, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
