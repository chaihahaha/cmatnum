#include "stdafx.h"
#include "fAxxeval3809.h"

inline int fAxxeval3809(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2701.data[0][0], 0, sizeof(bmats.Axx2701.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_25_6, bmats.Axx2660, bmats.Axx2700, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2701, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
