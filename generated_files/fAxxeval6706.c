#include "stdafx.h"
#include "fAxxeval6706.h"

inline int fAxxeval6706(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1919.data[0][0], 0, sizeof(bmats.Axx1919.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1113, bmats.Axx1117, bmats.Axx136, bmats.Axx1645, bmats.Axx1830, bmats.Axx1866, bmats.Axx2056, bmats.Axx2112, bmats.Axx227, bmats.Axx2825, bmats.Axx3322, bmats.Axx978, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1919, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
