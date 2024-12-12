#include "stdafx.h"
#include "fAxxeval828.h"

inline int fAxxeval828(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx829.data[0][0], 0, sizeof(bmats.Axx829.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx200, bmats.Axx201, bmats.Axx202, bmats.Axx203, bmats.Axx204, bmats.Axx205, bmats.Axx206, bmats.Axx207, bmats.Axx208, bmats.Axx209, bmats.Axx210, bmats.Axx211, bmats.Axx229, bmats.Axx828, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx829, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
