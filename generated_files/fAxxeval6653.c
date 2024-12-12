#include "stdafx.h"
#include "fAxxeval6653.h"

inline int fAxxeval6653(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3310.data[0][0], 0, sizeof(bmats.Axx3310.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_27_17, bmats.A_27_18, bmats.A_27_19, bmats.A_27_20, bmats.A_27_21, bmats.A_27_22, bmats.A_27_23, bmats.A_27_24, bmats.A_27_27, bmats.A_27_28, bmats.A_27_29, bmats.A_27_30, bmats.A_27_31, bmats.A_27_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3310, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
