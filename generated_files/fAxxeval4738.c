#include "stdafx.h"
#include "fAxxeval4738.h"

inline int fAxxeval4738(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx3381.data[0][0], 1);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx3383, bmats.Axx3385, bmats.Axx3386, bmats.Axx3389, bmats.Axx3390, bmats.Axx3393, bmats.Axx3394, bmats.Axx3397, bmats.Axx3398, bmats.Axx3401, bmats.Axx3402, bmats.Axx3406, bmats.Axx3411, bmats.Axx993, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3381, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
