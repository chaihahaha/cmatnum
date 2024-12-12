#include "stdafx.h"
#include "fAxxeval6179.h"

inline int fAxxeval6179(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx541.data[0][0], 0, sizeof(bmats.Axx541.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_15_28, bmats.Axx1653, bmats.Axx973, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx541, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
