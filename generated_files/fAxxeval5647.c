#include "stdafx.h"
#include "fAxxeval5647.h"

inline int fAxxeval5647(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2474.data[0][0], 0, sizeof(bmats.Axx2474.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1012, bmats.Axx1675, bmats.Axx1696, bmats.Axx1814, bmats.Axx1823, bmats.Axx1851, bmats.Axx211, bmats.Axx2167, bmats.Axx248, bmats.Axx2858, bmats.Axx2893, bmats.Axx2937, bmats.Axx3087, bmats.Axx3379, bmats.Axx3380, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2474, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}