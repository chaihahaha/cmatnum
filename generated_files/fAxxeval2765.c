#include "stdafx.h"
#include "fAxxeval2765.h"

inline int fAxxeval2765(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2112.data[0][0], 0, sizeof(bmats.Axx2112.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx2111, bmats.Axx802, bmats.Axx803, bmats.Axx804, bmats.Axx805, bmats.Axx806, bmats.Axx807, bmats.Axx808, bmats.Axx809, bmats.Axx810, bmats.Axx811, bmats.Axx812, bmats.Axx813, bmats.Axx857, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2112, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}