#include "stdafx.h"
#include "fAxxeval5233.h"

inline int fAxxeval5233(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3242.data[0][0], 0, sizeof(bmats.Axx3242.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_10_27, bmats.Axx1519, bmats.Axx538, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3242, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
