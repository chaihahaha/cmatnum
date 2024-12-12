#include "stdafx.h"
#include "fAxxeval7440.h"

inline int fAxxeval7440(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx778.data[0][0], 0, sizeof(bmats.Axx778.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_18_25, bmats.Axx1260, bmats.Axx1335, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx778, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
