#include "stdafx.h"
#include "fAxxeval1486.h"

inline int fAxxeval1486(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1487.data[0][0], 0, sizeof(bmats.Axx1487.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_31_30, };
    double A_coeffs[1] = {16, };
    matlincomb_double_contiguous(bmats.Axx1487, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
