#include "stdafx.h"
#include "fAxxeval4550.h"

inline int fAxxeval4550(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3291.data[0][0], 0, sizeof(bmats.Axx3291.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx3270, bmats.Axx3271, bmats.Axx3272, bmats.Axx3273, bmats.Axx3276, bmats.Axx3277, bmats.Axx3278, bmats.Axx3279, bmats.Axx3280, bmats.Axx3281, bmats.Axx3284, bmats.Axx3286, bmats.Axx985, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3291, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
