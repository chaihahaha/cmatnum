#include "stdafx.h"
#include "fAxxeval7507.h"

inline int fAxxeval7507(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2288.data[0][0], 0, sizeof(bmats.Axx2288.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_26_26, };
    double A_coeffs[1] = {-15, };
    matlincomb_double_contiguous(bmats.Axx2288, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
