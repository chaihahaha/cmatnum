#include "stdafx.h"
#include "fAxxeval6430.h"

inline int fAxxeval6430(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1936.data[0][0], 0, sizeof(bmats.Axx1936.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1772, bmats.Axx1899, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx1936, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
