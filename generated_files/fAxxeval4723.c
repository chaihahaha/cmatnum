#include "stdafx.h"
#include "fAxxeval4723.h"

inline int fAxxeval4723(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3407.data[0][0], 0, sizeof(bmats.Axx3407.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx3342, bmats.Axx3381, bmats.Axx3383, bmats.Axx3385, bmats.Axx3386, bmats.Axx3389, bmats.Axx3390, bmats.Axx3394, bmats.Axx3397, bmats.Axx3398, bmats.Axx3401, bmats.Axx3402, bmats.Axx3404, bmats.Axx3406, bmats.Axx993, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3407, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
