#include "stdafx.h"
#include "fAxxeval7422.h"

inline int fAxxeval7422(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2485.data[0][0], 0, sizeof(bmats.Axx2485.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_18_20, bmats.Axx1792, bmats.Axx2830, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx2485, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
