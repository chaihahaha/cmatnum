#include "stdafx.h"
#include "fAxxeval7114.h"

inline int fAxxeval7114(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2403.data[0][0], 0, sizeof(bmats.Axx2403.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1237, bmats.Axx1238, bmats.Axx2161, };
    double A_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2403, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}