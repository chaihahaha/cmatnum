#include "stdafx.h"
#include "fAxxeval7445.h"

inline int fAxxeval7445(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2508.data[0][0], 0, sizeof(bmats.Axx2508.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_18_27, bmats.Axx1844, bmats.Axx2439, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2508, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
