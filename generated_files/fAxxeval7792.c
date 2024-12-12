#include "stdafx.h"
#include "fAxxeval7792.h"

inline int fAxxeval7792(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2938.data[0][0], 0, sizeof(bmats.Axx2938.data[0][0])*BL*BL);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1385, bmats.Axx1427, bmats.Axx2459, bmats.Axx2898, };
    double A_coeffs[4] = {1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2938, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
