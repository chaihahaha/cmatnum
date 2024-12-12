#include "stdafx.h"
#include "fAxxeval1730.h"

inline int fAxxeval1730(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1643.data[0][0], 0, sizeof(bmats.Axx1643.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1633, bmats.Axx200, bmats.Axx201, bmats.Axx202, bmats.Axx203, bmats.Axx206, bmats.Axx207, bmats.Axx208, bmats.Axx209, bmats.Axx210, bmats.Axx211, bmats.Axx229, bmats.Axx828, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1643, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
