#include "stdafx.h"
#include "fAxxeval4762.h"

inline int fAxxeval4762(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx595.data[0][0], 0, sizeof(bmats.Axx595.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_1_21, bmats.Axx3388, bmats.Axx3393, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx595, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
