#include "stdafx.h"
#include "fAxxeval6096.h"

inline int fAxxeval6096(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1496.data[0][0], 0, sizeof(bmats.Axx1496.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1501, bmats.Axx2939, bmats.Axx2942, bmats.Axx2944, bmats.Axx2946, bmats.Axx2947, bmats.Axx2950, bmats.Axx2951, bmats.Axx2954, bmats.Axx2960, bmats.Axx2961, bmats.Axx2964, bmats.Axx2965, bmats.Axx2975, bmats.Axx975, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1496, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
