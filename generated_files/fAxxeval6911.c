#include "stdafx.h"
#include "fAxxeval6911.h"

inline int fAxxeval6911(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx32.data[0][0], 0, sizeof(bmats.Axx32.data[0][0])*BL*BL);
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.Axx1072, bmats.Axx1170, bmats.Axx1173, bmats.Axx1176, bmats.Axx1180, bmats.Axx1891, bmats.Axx2178, bmats.Axx3327, bmats.Axx862, };
    double A_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx32, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
