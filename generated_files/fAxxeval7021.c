#include "stdafx.h"
#include "fAxxeval7021.h"

inline int fAxxeval7021(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2636.data[0][0], 0, sizeof(bmats.Axx2636.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_21_27, bmats.Axx1169, bmats.Axx1892, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2636, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
