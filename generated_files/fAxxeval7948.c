#include "stdafx.h"
#include "fAxxeval7948.h"

inline int fAxxeval7948(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx30.data[0][0], 0, sizeof(bmats.Axx30.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx104, bmats.Axx1456, bmats.Axx2232, };
    double A_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx30, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
