#include "stdafx.h"
#include "fAxxeval8155.h"

inline int fAxxeval8155(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1296.data[0][0], 0, sizeof(bmats.Axx1296.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_28_20, bmats.Axx1413, bmats.Axx1475, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1296, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}