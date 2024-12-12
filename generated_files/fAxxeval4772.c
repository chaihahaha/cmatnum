#include "stdafx.h"
#include "fAxxeval4772.h"

inline int fAxxeval4772(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3404.data[0][0], 0, sizeof(bmats.Axx3404.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_1_26, bmats.Axx1549, bmats.Axx3399, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx3404, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
