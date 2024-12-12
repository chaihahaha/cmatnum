#include "stdafx.h"
#include "fAxxeval6191.h"

inline int fAxxeval6191(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2303.data[0][0], 0, sizeof(bmats.Axx2303.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1526, bmats.Axx1894, bmats.Axx1912, bmats.Axx2002, bmats.Axx2207, bmats.Axx2540, bmats.Axx2640, bmats.Axx2852, bmats.Axx2857, bmats.Axx2900, bmats.Axx2935, bmats.Axx3387, bmats.Axx465, bmats.Axx541, bmats.Axx824, bmats.Axx993, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2303, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
