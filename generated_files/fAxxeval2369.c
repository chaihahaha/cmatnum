#include "stdafx.h"
#include "fAxxeval2369.h"

inline int fAxxeval2369(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1957.data[0][0], 0, sizeof(bmats.Axx1957.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1950, bmats.Axx637, bmats.Axx638, bmats.Axx639, bmats.Axx640, bmats.Axx641, bmats.Axx642, bmats.Axx643, bmats.Axx644, bmats.Axx645, bmats.Axx646, bmats.Axx647, bmats.Axx648, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1957, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
