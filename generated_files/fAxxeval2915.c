#include "stdafx.h"
#include "fAxxeval2915.h"

inline int fAxxeval2915(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx656.data[0][0], 0, sizeof(bmats.Axx656.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx850, bmats.Axx851, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx656, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}