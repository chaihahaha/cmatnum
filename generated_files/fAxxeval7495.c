#include "stdafx.h"
#include "fAxxeval7495.h"

inline int fAxxeval7495(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2596.data[0][0], 0, sizeof(bmats.Axx2596.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx162, bmats.Axx2559, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx2596, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}