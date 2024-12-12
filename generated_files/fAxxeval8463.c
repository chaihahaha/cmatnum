#include "stdafx.h"
#include "fAxxeval8463.h"

inline int fAxxeval8463(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx347.data[0][0], 0, sizeof(bmats.Axx347.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1562, bmats.Axx651, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx347, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
