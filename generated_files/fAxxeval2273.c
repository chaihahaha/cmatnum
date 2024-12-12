#include "stdafx.h"
#include "fAxxeval2273.h"

inline int fAxxeval2273(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1908.data[0][0], 0, sizeof(bmats.Axx1908.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1891, bmats.Axx1901, bmats.Axx585, bmats.Axx586, bmats.Axx587, bmats.Axx588, bmats.Axx589, bmats.Axx590, bmats.Axx593, bmats.Axx594, bmats.Axx595, bmats.Axx596, bmats.Axx904, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1908, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
