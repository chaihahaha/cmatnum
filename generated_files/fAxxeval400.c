#include "stdafx.h"
#include "fAxxeval400.h"

inline int fAxxeval400(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx401.data[0][0], 0, sizeof(bmats.Axx401.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_6_9, };
    double A_coeffs[1] = {2, };
    matlincomb_double_contiguous(bmats.Axx401, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}