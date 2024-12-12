#include "stdafx.h"
#include "fAxxeval6238.h"

inline int fAxxeval6238(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2884.data[0][0], 0, sizeof(bmats.Axx2884.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1004, bmats.Axx1504, bmats.Axx1528, bmats.Axx1859, bmats.Axx1909, bmats.Axx1946, bmats.Axx2086, bmats.Axx2120, bmats.Axx2235, bmats.Axx2566, bmats.Axx2711, bmats.Axx3009, bmats.Axx302, bmats.Axx3289, bmats.Axx686, bmats.Axx899, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2884, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
