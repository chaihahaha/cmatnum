#include "stdafx.h"
#include "fAxxeval2290.h"

inline int fAxxeval2290(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1918.data[0][0], 0, sizeof(bmats.Axx1918.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_3_4, bmats.Axx1897, bmats.Axx1899, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1918, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
