#include "stdafx.h"
#include "fAxxeval6897.h"

inline int fAxxeval6897(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2300.data[0][0], 0, sizeof(bmats.Axx2300.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_22_18, bmats.Axx1032, bmats.Axx1114, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx2300, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
