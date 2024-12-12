#include "stdafx.h"
#include "fAxxeval3649.h"

inline int fAxxeval3649(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2559.data[0][0], 0, sizeof(bmats.Axx2559.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_18_9, bmats.Axx2525, bmats.Axx2558, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2559, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
