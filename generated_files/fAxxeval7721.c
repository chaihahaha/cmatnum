#include "stdafx.h"
#include "fAxxeval7721.h"

inline int fAxxeval7721(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx74.data[0][0], 0, sizeof(bmats.Axx74.data[0][0])*BL*BL);
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.Axx1427, bmats.Axx1442, bmats.Axx1527, bmats.Axx203, bmats.Axx3024, bmats.Axx3140, bmats.Axx521, bmats.Axx579, };
    double A_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx74, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
