#include "stdafx.h"
#include "fAxxeval6976.h"

inline int fAxxeval6976(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx152.data[0][0], 0, sizeof(bmats.Axx152.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1172, bmats.Axx1620, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx152, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
