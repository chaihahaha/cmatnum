#include "stdafx.h"
#include "fAxxeval6990.h"

inline int fAxxeval6990(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1896.data[0][0], 0, sizeof(bmats.Axx1896.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1072, bmats.Axx1128, bmats.Axx1151, bmats.Axx1154, bmats.Axx1158, bmats.Axx1167, bmats.Axx1170, bmats.Axx1173, bmats.Axx1176, bmats.Axx1578, bmats.Axx1891, bmats.Axx2178, bmats.Axx3327, bmats.Axx862, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1896, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
