#include "stdafx.h"
#include "fAxxeval6102.h"

inline int fAxxeval6102(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2075.data[0][0], 0, sizeof(bmats.Axx2075.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1516, bmats.Axx1521, bmats.Axx1729, bmats.Axx1757, bmats.Axx1803, bmats.Axx1948, bmats.Axx2135, bmats.Axx2714, bmats.Axx276, bmats.Axx3087, bmats.Axx3400, bmats.Axx3410, bmats.Axx368, bmats.Axx796, bmats.Axx805, bmats.Axx828, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2075, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
