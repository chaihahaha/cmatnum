#include "stdafx.h"
#include "fAxxeval6426.h"

inline int fAxxeval6426(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx700.data[0][0], 0, sizeof(bmats.Axx700.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx138, bmats.Axx1571, bmats.Axx16, bmats.Axx1616, bmats.Axx1781, bmats.Axx1804, bmats.Axx1865, bmats.Axx1899, bmats.Axx2069, bmats.Axx2111, bmats.Axx2468, bmats.Axx579, bmats.Axx602, bmats.Axx647, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx700, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
