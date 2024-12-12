#include "stdafx.h"
#include "fAxxeval3392.h"

inline int fAxxeval3392(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2338.data[0][0], 0, sizeof(bmats.Axx2338.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_21_13, bmats.Axx2333, bmats.Axx2337, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2338, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
