#include "stdafx.h"
#include "fAxxeval2616.h"

inline int fAxxeval2616(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx666.data[0][0], 0, sizeof(bmats.Axx666.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_8_12, bmats.Axx676, bmats.Axx683, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx666, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
