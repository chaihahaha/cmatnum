#include "stdafx.h"
#include "fAxxeval5771.h"

inline int fAxxeval5771(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1529.data[0][0], 0, sizeof(bmats.Axx1529.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_13_27, bmats.Axx1496, bmats.Axx1759, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1529, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}