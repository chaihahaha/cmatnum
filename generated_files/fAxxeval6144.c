#include "stdafx.h"
#include "fAxxeval6144.h"

inline int fAxxeval6144(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3245.data[0][0], 0, sizeof(bmats.Axx3245.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1797, bmats.Axx2720, bmats.Axx2722, bmats.Axx2723, bmats.Axx2726, bmats.Axx2728, bmats.Axx2729, bmats.Axx2732, bmats.Axx2733, bmats.Axx2740, bmats.Axx2741, bmats.Axx2744, bmats.Axx2746, bmats.Axx2752, bmats.Axx968, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3245, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}