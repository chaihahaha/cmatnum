#include "stdafx.h"
#include "fAxxeval5814.h"

inline int fAxxeval5814(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3087.data[0][0], 0, sizeof(bmats.Axx3087.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_12_29, bmats.Axx1851, bmats.Axx2930, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx3087, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
