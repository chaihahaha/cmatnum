#include "stdafx.h"
#include "fAxxeval6553.h"

inline int fAxxeval6553(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx491.data[0][0], 0, sizeof(bmats.Axx491.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1053, bmats.Axx1057, bmats.Axx1659, bmats.Axx1756, bmats.Axx1814, bmats.Axx1900, bmats.Axx2267, bmats.Axx2469, bmats.Axx3054, bmats.Axx3118, bmats.Axx487, bmats.Axx499, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx491, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
