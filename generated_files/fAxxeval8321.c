#include "stdafx.h"
#include "fAxxeval8321.h"

inline int fAxxeval8321(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3151.data[0][0], 0, sizeof(bmats.Axx3151.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_23_23, };
    double A_coeffs[1] = {16, };
    matlincomb_double_contiguous(bmats.Axx3151, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}