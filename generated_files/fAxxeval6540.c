#include "stdafx.h"
#include "fAxxeval6540.h"

inline int fAxxeval6540(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1019.data[0][0], 0, sizeof(bmats.Axx1019.data[0][0])*BL*BL);
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.Axx1053, bmats.Axx1057, bmats.Axx1079, bmats.Axx1659, bmats.Axx1756, bmats.Axx1814, bmats.Axx1900, bmats.Axx2267, bmats.Axx2469, bmats.Axx3118, bmats.Axx487, };
    double A_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1019, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}