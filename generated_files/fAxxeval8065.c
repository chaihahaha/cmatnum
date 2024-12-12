#include "stdafx.h"
#include "fAxxeval8065.h"

inline int fAxxeval8065(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx349.data[0][0], 0, sizeof(bmats.Axx349.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1512, bmats.Axx1652, bmats.Axx1723, bmats.Axx2435, bmats.Axx2508, bmats.Axx2636, bmats.Axx2954, bmats.Axx3021, bmats.Axx3047, bmats.Axx3364, bmats.Axx422, bmats.Axx704, bmats.Axx733, bmats.Axx777, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx349, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
