#include "stdafx.h"
#include "fAxxeval6641.h"

inline int fAxxeval6641(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2160.data[0][0], 0, sizeof(bmats.Axx2160.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_27_17, bmats.A_27_18, bmats.A_27_19, bmats.A_27_20, bmats.A_27_21, bmats.A_27_22, bmats.A_27_23, bmats.A_27_24, bmats.A_27_25, bmats.A_27_26, bmats.A_27_27, bmats.A_27_28, bmats.A_27_29, bmats.A_27_30, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2160, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
