#include "stdafx.h"
#include "fAxxeval7716.h"

inline int fAxxeval7716(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3041.data[0][0], 0, sizeof(bmats.Axx3041.data[0][0])*BL*BL);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.Axx1427, bmats.Axx1442, bmats.Axx1527, bmats.Axx2015, bmats.Axx3024, bmats.Axx3140, bmats.Axx521, };
    double A_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3041, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
