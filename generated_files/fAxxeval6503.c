#include "stdafx.h"
#include "fAxxeval6503.h"

inline int fAxxeval6503(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2015.data[0][0], 0, sizeof(bmats.Axx2015.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1542, bmats.Axx1624, bmats.Axx1629, bmats.Axx1755, bmats.Axx1799, bmats.Axx1852, bmats.Axx1890, bmats.Axx1945, bmats.Axx1991, bmats.Axx3275, bmats.Axx636, bmats.Axx653, bmats.Axx704, bmats.Axx771, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2015, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
