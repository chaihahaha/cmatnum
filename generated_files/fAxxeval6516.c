#include "stdafx.h"
#include "fAxxeval6516.h"

inline int fAxxeval6516(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2946.data[0][0], 0, sizeof(bmats.Axx2946.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1620, bmats.Axx175, bmats.Axx183, bmats.Axx442, bmats.Axx484, bmats.Axx503, bmats.Axx566, bmats.Axx580, bmats.Axx616, bmats.Axx661, bmats.Axx721, bmats.Axx792, bmats.Axx813, bmats.Axx987, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2946, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
