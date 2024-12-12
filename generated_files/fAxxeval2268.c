#include "stdafx.h"
#include "fAxxeval2268.h"

inline int fAxxeval2268(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1903.data[0][0], 0, sizeof(bmats.Axx1903.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1892, bmats.Axx1902, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx1903, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
