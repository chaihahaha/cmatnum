#include "stdafx.h"
#include "fAxxeval7043.h"

inline int fAxxeval7043(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx582.data[0][0], 0, sizeof(bmats.Axx582.data[0][0])*BL*BL);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.Axx1206, bmats.Axx1230, bmats.Axx1237, bmats.Axx1567, bmats.Axx2545, bmats.Axx2849, bmats.Axx845, };
    double A_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx582, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
