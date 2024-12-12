#include "stdafx.h"
#include "fAxxeval4639.h"

inline int fAxxeval4639(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3355.data[0][0], 0, sizeof(bmats.Axx3355.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2223, bmats.Axx2285, bmats.Axx2356, bmats.Axx2423, bmats.Axx2491, bmats.Axx2554, bmats.Axx2622, bmats.Axx2701, bmats.Axx2768, bmats.Axx2830, bmats.Axx2912, bmats.Axx2996, bmats.Axx3075, bmats.Axx3141, bmats.Axx3209, bmats.Axx3353, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3355, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
