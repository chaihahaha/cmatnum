#include "stdafx.h"
#include "fAxxeval6985.h"

inline int fAxxeval6985(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx699.data[0][0], 0, sizeof(bmats.Axx699.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1072, bmats.Axx1128, bmats.Axx1151, bmats.Axx1154, bmats.Axx1167, bmats.Axx1170, bmats.Axx1173, bmats.Axx1180, bmats.Axx1578, bmats.Axx1891, bmats.Axx2178, bmats.Axx3327, bmats.Axx862, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx699, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
