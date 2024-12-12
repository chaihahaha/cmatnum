#include "stdafx.h"
#include "fAxxeval6212.h"

inline int fAxxeval6212(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1778.data[0][0], 0, sizeof(bmats.Axx1778.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1549, bmats.Axx1557, bmats.Axx1668, bmats.Axx1702, bmats.Axx2036, bmats.Axx2071, bmats.Axx2097, bmats.Axx2204, bmats.Axx2715, bmats.Axx3012, bmats.Axx3255, bmats.Axx3385, bmats.Axx3396, bmats.Axx374, bmats.Axx420, bmats.Axx664, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1778, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
