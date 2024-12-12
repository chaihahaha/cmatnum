#include "stdafx.h"
#include "fAxxeval5853.h"

inline int fAxxeval5853(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx144.data[0][0], 0, sizeof(bmats.Axx144.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_12_25, bmats.Axx157, bmats.Axx3202, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx144, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
