#include "stdafx.h"
#include "fAxxeval1880.h"

inline int fAxxeval1880(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1707.data[0][0], 0, sizeof(bmats.Axx1707.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1662, bmats.Axx1706, bmats.Axx301, bmats.Axx305, bmats.Axx310, bmats.Axx313, bmats.Axx315, bmats.Axx317, bmats.Axx319, bmats.Axx321, bmats.Axx323, bmats.Axx325, bmats.Axx371, bmats.Axx374, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1707, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
