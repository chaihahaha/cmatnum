#include "stdafx.h"
#include "fAxxeval2479.h"

inline int fAxxeval2479(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2011.data[0][0], 0, sizeof(bmats.Axx2011.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1992, bmats.Axx2002, bmats.Axx682, bmats.Axx683, bmats.Axx684, bmats.Axx685, bmats.Axx686, bmats.Axx687, bmats.Axx688, bmats.Axx689, bmats.Axx690, bmats.Axx691, bmats.Axx735, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2011, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
