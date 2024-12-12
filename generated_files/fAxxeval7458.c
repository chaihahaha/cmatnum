#include "stdafx.h"
#include "fAxxeval7458.h"

inline int fAxxeval7458(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx604.data[0][0], 0, sizeof(bmats.Axx604.data[0][0])*BL*BL);
    int n_A_mats = 9;
    double_cmat A_mats[9] = {bmats.Axx1125, bmats.Axx1358, bmats.Axx1360, bmats.Axx1371, bmats.Axx1644, bmats.Axx2305, bmats.Axx3133, bmats.Axx404, bmats.Axx643, };
    double A_coeffs[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx604, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
