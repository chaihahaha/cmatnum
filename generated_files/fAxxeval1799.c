#include "stdafx.h"
#include "fAxxeval1799.h"

inline int fAxxeval1799(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1669.data[0][0], 0, sizeof(bmats.Axx1669.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1600, bmats.Axx1650, bmats.Axx1652, bmats.Axx1654, bmats.Axx1657, bmats.Axx1658, bmats.Axx238, bmats.Axx240, bmats.Axx276, bmats.Axx279, bmats.Axx285, bmats.Axx289, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1669, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
