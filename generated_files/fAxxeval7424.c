#include "stdafx.h"
#include "fAxxeval7424.h"

inline int fAxxeval7424(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3045.data[0][0], 0, sizeof(bmats.Axx3045.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_18_22, bmats.Axx1331, bmats.Axx501, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3045, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
