#include "stdafx.h"
#include "fAxxeval2776.h"

inline int fAxxeval2776(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2123.data[0][0], 0, sizeof(bmats.Axx2123.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx2101, bmats.Axx2111, bmats.Axx802, bmats.Axx803, bmats.Axx804, bmats.Axx805, bmats.Axx806, bmats.Axx807, bmats.Axx810, bmats.Axx811, bmats.Axx812, bmats.Axx813, bmats.Axx857, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2123, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}