#include "stdafx.h"
#include "fAxxeval8516.h"

inline int fAxxeval8516(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx787.data[0][0], 0, sizeof(bmats.Axx787.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1573, bmats.Axx1649, bmats.Axx1662, bmats.Axx2117, bmats.Axx2300, bmats.Axx2301, bmats.Axx2608, bmats.Axx2679, bmats.Axx286, bmats.Axx3128, bmats.Axx3234, bmats.Axx567, bmats.Axx809, bmats.Axx869, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx787, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
