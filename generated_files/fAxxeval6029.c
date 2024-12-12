#include "stdafx.h"
#include "fAxxeval6029.h"

inline int fAxxeval6029(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2017.data[0][0], 0, sizeof(bmats.Axx2017.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_16_25, bmats.Axx1656, bmats.Axx3300, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2017, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
