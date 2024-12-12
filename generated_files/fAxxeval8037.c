#include "stdafx.h"
#include "fAxxeval8037.h"

inline int fAxxeval8037(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1316.data[0][0], 0, sizeof(bmats.Axx1316.data[0][0])*BL*BL);
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.Axx1423, bmats.Axx1473, bmats.Axx1476, bmats.Axx1593, bmats.Axx1611, bmats.Axx1826, bmats.Axx2159, bmats.Axx3156, bmats.Axx317, bmats.Axx3220, bmats.Axx3380, };
    double A_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1316, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
