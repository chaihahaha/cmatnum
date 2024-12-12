#include "stdafx.h"
#include "fAxxeval5033.h"

inline int fAxxeval5033(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx473.data[0][0], 0, sizeof(bmats.Axx473.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_3_22, bmats.Axx824, bmats.Axx996, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx473, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
