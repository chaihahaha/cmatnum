#include "stdafx.h"
#include "fAxxeval1760.h"

inline int fAxxeval1760(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1602.data[0][0], 0, sizeof(bmats.Axx1602.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_15_14, bmats.Axx1595, bmats.Axx1612, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1602, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
