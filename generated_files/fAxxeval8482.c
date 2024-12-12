#include "stdafx.h"
#include "fAxxeval8482.h"

inline int fAxxeval8482(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1486.data[0][0], 0, sizeof(bmats.Axx1486.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_23_17, bmats.A_23_18, bmats.A_23_21, bmats.A_23_22, bmats.A_23_23, bmats.A_23_24, bmats.A_23_25, bmats.A_23_26, bmats.A_23_27, bmats.A_23_28, bmats.A_23_29, bmats.A_23_30, bmats.A_23_31, bmats.A_23_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1486, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
