#include "stdafx.h"
#include "fAxxeval2295.h"

inline int fAxxeval2295(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1920.data[0][0], 0, sizeof(bmats.Axx1920.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1894, bmats.Axx1901, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx1920, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
