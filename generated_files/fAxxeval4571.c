#include "stdafx.h"
#include "fAxxeval4571.h"

inline int fAxxeval4571(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx3277.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx3270, bmats.Axx3271, bmats.Axx3272, bmats.Axx3273, bmats.Axx3274, bmats.Axx3275, bmats.Axx3276, bmats.Axx3278, bmats.Axx3279, bmats.Axx3280, bmats.Axx3281, bmats.Axx3284, bmats.Axx3286, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3277, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
