#include "stdafx.h"
#include "fAxxeval6901.h"

inline int fAxxeval6901(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2110.data[0][0], 0, sizeof(bmats.Axx2110.data[0][0])*BL*BL);
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.Axx1072, bmats.Axx1167, bmats.Axx1170, bmats.Axx1173, bmats.Axx1176, bmats.Axx1180, bmats.Axx3327, bmats.Axx862, };
    double A_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2110, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
