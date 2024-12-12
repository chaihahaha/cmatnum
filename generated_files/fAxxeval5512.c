#include "stdafx.h"
#include "fAxxeval5512.h"

inline int fAxxeval5512(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3009.data[0][0], 0, sizeof(bmats.Axx3009.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1009, bmats.Axx1666, };
    double A_coeffs[2] = {-1, 1, };
    matlincomb_double_contiguous(bmats.Axx3009, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
