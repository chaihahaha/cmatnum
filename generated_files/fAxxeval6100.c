#include "stdafx.h"
#include "fAxxeval6100.h"

inline int fAxxeval6100(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2015.data[0][0], 0, sizeof(bmats.Axx2015.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1017, bmats.Axx1023, bmats.Axx1499, bmats.Axx1544, bmats.Axx1545, bmats.Axx1752, bmats.Axx2083, bmats.Axx2171, bmats.Axx2636, bmats.Axx2896, bmats.Axx2927, bmats.Axx3124, bmats.Axx367, bmats.Axx689, bmats.Axx735, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2015, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}