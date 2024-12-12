#include "stdafx.h"
#include "fAxxeval7036.h"

inline int fAxxeval7036(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2730.data[0][0], 0, sizeof(bmats.Axx2730.data[0][0])*BL*BL);
    int n_A_mats = 5;
    double_cmat A_mats[5] = {bmats.Axx1230, bmats.Axx1233, bmats.Axx1237, bmats.Axx2545, bmats.Axx2849, };
    double A_coeffs[5] = {1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2730, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
