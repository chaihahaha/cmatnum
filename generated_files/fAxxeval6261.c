#include "stdafx.h"
#include "fAxxeval6261.h"

inline int fAxxeval6261(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1972.data[0][0], 0, sizeof(bmats.Axx1972.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1597, bmats.Axx1655, bmats.Axx1728, bmats.Axx1802, bmats.Axx192, bmats.Axx1980, bmats.Axx1986, bmats.Axx2136, bmats.Axx2150, bmats.Axx2504, bmats.Axx2639, bmats.Axx3402, bmats.Axx3408, bmats.Axx593, bmats.Axx64, bmats.Axx76, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1972, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
