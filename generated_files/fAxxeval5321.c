#include "stdafx.h"
#include "fAxxeval5321.h"

inline int fAxxeval5321(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx134.data[0][0], 0, sizeof(bmats.Axx134.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_9_27, bmats.Axx1743, bmats.Axx942, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx134, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
