#include "stdafx.h"
#include "fAxxeval7612.h"

inline int fAxxeval7612(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2410.data[0][0], 0, sizeof(bmats.Axx2410.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1304, bmats.Axx688, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx2410, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}