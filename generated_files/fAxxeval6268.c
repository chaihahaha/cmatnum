#include "stdafx.h"
#include "fAxxeval6268.h"

inline int fAxxeval6268(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2722.data[0][0], 0, sizeof(bmats.Axx2722.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1972, bmats.Axx2509, bmats.Axx2510, bmats.Axx2513, bmats.Axx2515, bmats.Axx2517, bmats.Axx2518, bmats.Axx2520, bmats.Axx2523, bmats.Axx2524, bmats.Axx2527, bmats.Axx2529, bmats.Axx2530, bmats.Axx2533, bmats.Axx2538, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2722, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
