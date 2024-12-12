#include "stdafx.h"
#include "fAxxeval6495.h"

inline int fAxxeval6495(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1885.data[0][0], 0, sizeof(bmats.Axx1885.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1598, bmats.Axx1788, bmats.Axx1837, bmats.Axx1873, bmats.Axx1879, bmats.Axx1927, bmats.Axx684, bmats.Axx705, bmats.Axx712, bmats.Axx713, bmats.Axx763, bmats.Axx776, bmats.Axx818, bmats.Axx882, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1885, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
