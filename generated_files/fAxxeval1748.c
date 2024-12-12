#include "stdafx.h"
#include "fAxxeval1748.h"

inline int fAxxeval1748(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx202.data[0][0], 0, sizeof(bmats.Axx202.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_15_6, bmats.Axx1596, bmats.Axx206, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx202, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
