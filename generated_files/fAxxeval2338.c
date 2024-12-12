#include "stdafx.h"
#include "fAxxeval2338.h"

inline int fAxxeval2338(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1935.data[0][0], 0, sizeof(bmats.Axx1935.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_3_14, };
    double A_coeffs[1] = {16, };
    matlincomb_double_contiguous(bmats.Axx1935, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
