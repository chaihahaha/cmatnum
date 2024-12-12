#include "stdafx.h"
#include "fAxxeval7503.h"

inline int fAxxeval7503(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2023.data[0][0], 0, sizeof(bmats.Axx2023.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx162, bmats.Axx2703, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx2023, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
