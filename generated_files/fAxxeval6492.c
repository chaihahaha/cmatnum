#include "stdafx.h"
#include "fAxxeval6492.h"

inline int fAxxeval6492(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx866.data[0][0], 0, sizeof(bmats.Axx866.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1583, bmats.Axx1598, bmats.Axx1788, bmats.Axx1837, bmats.Axx1879, bmats.Axx1927, bmats.Axx1975, bmats.Axx684, bmats.Axx705, bmats.Axx712, bmats.Axx763, bmats.Axx776, bmats.Axx818, bmats.Axx882, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx866, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
