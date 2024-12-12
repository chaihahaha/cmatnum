#include "stdafx.h"
#include "fAxxeval6341.h"

inline int fAxxeval6341(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3047.data[0][0], 0, sizeof(bmats.Axx3047.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1588, bmats.Axx1602, bmats.Axx1791, bmats.Axx1795, bmats.Axx1842, bmats.Axx1851, bmats.Axx2110, bmats.Axx219, bmats.Axx549, bmats.Axx638, bmats.Axx646, bmats.Axx769, bmats.Axx811, bmats.Axx845, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3047, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
