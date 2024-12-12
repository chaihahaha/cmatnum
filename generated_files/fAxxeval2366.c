#include "stdafx.h"
#include "fAxxeval2366.h"

inline int fAxxeval2366(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1954.data[0][0], 0, sizeof(bmats.Axx1954.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1950, bmats.Axx621, bmats.Axx637, bmats.Axx638, bmats.Axx641, bmats.Axx642, bmats.Axx643, bmats.Axx644, bmats.Axx645, bmats.Axx646, bmats.Axx647, bmats.Axx648, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1954, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
