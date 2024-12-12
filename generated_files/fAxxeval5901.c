#include "stdafx.h"
#include "fAxxeval5901.h"

inline int fAxxeval5901(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1555.data[0][0], 0, sizeof(bmats.Axx1555.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_11_17, bmats.A_11_18, bmats.A_11_19, bmats.A_11_20, bmats.A_11_21, bmats.A_11_22, bmats.A_11_23, bmats.A_11_24, bmats.A_11_25, bmats.A_11_26, bmats.A_11_27, bmats.A_11_28, bmats.A_11_31, bmats.A_11_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1555, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
