#include "stdafx.h"
#include "fAxxeval3038.h"

inline int fAxxeval3038(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx476.data[0][0], 0, sizeof(bmats.Axx476.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx158, bmats.Axx1887, bmats.Axx712, bmats.Axx891, bmats.Axx892, bmats.Axx893, bmats.Axx894, bmats.Axx895, bmats.Axx896, bmats.Axx897, bmats.Axx898, bmats.Axx900, bmats.Axx901, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx476, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}