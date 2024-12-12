#include "stdafx.h"
#include "fAxxeval6547.h"

inline int fAxxeval6547(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2272.data[0][0], 0, sizeof(bmats.Axx2272.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1057, bmats.Axx1079, bmats.Axx1081, bmats.Axx1659, bmats.Axx1756, bmats.Axx1814, bmats.Axx1900, bmats.Axx2267, bmats.Axx2469, bmats.Axx3054, bmats.Axx3118, bmats.Axx487, bmats.Axx499, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2272, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
