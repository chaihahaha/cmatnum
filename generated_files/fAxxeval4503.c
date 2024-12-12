#include "stdafx.h"
#include "fAxxeval4503.h"

inline int fAxxeval4503(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx681.data[0][0], 0, sizeof(bmats.Axx681.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1584, bmats.Axx1787, bmats.Axx1838, bmats.Axx1878, bmats.Axx1926, bmats.Axx1943, bmats.Axx2081, bmats.Axx2098, bmats.Axx2105, bmats.Axx488, bmats.Axx502, bmats.Axx513, bmats.Axx552, bmats.Axx666, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx681, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
