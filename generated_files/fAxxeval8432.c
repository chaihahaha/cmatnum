#include "stdafx.h"
#include "fAxxeval8432.h"

inline int fAxxeval8432(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx513.data[0][0], 0, sizeof(bmats.Axx513.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_23_28, bmats.Axx1180, bmats.Axx757, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx513, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}