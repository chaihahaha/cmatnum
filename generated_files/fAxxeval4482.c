#include "stdafx.h"
#include "fAxxeval4482.h"

inline int fAxxeval4482(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx33.data[0][0], 0, sizeof(bmats.Axx33.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1572, bmats.Axx174, bmats.Axx1813, bmats.Axx187, bmats.Axx1919, bmats.Axx202, bmats.Axx483, bmats.Axx489, bmats.Axx521, bmats.Axx539, bmats.Axx622, bmats.Axx764, bmats.Axx874, bmats.Axx894, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx33, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}