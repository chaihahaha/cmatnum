#include "stdafx.h"
#include "fAxxeval8154.h"

inline int fAxxeval8154(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1841.data[0][0], 0, sizeof(bmats.Axx1841.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_28_19, bmats.Axx1413, bmats.Axx1472, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1841, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
