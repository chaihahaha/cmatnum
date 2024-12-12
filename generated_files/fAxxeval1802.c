#include "stdafx.h"
#include "fAxxeval1802.h"

inline int fAxxeval1802(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1671.data[0][0], 0, sizeof(bmats.Axx1671.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1600, bmats.Axx1650, bmats.Axx1652, bmats.Axx1654, bmats.Axx1657, bmats.Axx1658, bmats.Axx238, bmats.Axx240, bmats.Axx244, bmats.Axx276, bmats.Axx279, bmats.Axx282, bmats.Axx289, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1671, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
