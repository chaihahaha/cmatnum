#include "stdafx.h"
#include "fAxxeval1962.h"

inline int fAxxeval1962(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx378.data[0][0], 0, sizeof(bmats.Axx378.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1702, bmats.Axx1732, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx378, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
