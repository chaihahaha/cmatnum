#include "stdafx.h"
#include "fAxxeval8162.h"

inline int fAxxeval8162(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx728.data[0][0], 0, sizeof(bmats.Axx728.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.A_28_17, bmats.A_28_18, bmats.A_28_19, bmats.A_28_20, bmats.A_28_21, bmats.A_28_22, bmats.A_28_25, bmats.A_28_26, bmats.A_28_27, bmats.A_28_28, bmats.A_28_29, bmats.A_28_30, bmats.A_28_31, bmats.A_28_32, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx728, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}