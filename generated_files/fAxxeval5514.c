#include "stdafx.h"
#include "fAxxeval5514.h"

inline int fAxxeval5514(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx538.data[0][0], 0, sizeof(bmats.Axx538.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx417, bmats.Axx603, };
    double A_coeffs[2] = {-1, -1, };
    matlincomb_double_contiguous(bmats.Axx538, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
