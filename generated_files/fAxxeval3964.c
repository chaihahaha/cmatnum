#include "stdafx.h"
#include "fAxxeval3964.h"

inline int fAxxeval3964(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2837.data[0][0], 0, sizeof(bmats.Axx2837.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_23_4, bmats.Axx2799, bmats.Axx2836, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2837, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
