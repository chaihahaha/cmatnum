#include "stdafx.h"
#include "fAxxeval6117.h"

inline int fAxxeval6117(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3380.data[0][0], 0, sizeof(bmats.Axx3380.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1012, bmats.Axx154, bmats.Axx1678, bmats.Axx1759, bmats.Axx1944, bmats.Axx195, bmats.Axx3251, bmats.Axx3393, bmats.Axx3394, bmats.Axx380, bmats.Axx473, bmats.Axx478, bmats.Axx586, bmats.Axx774, bmats.Axx834, bmats.Axx904, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3380, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
