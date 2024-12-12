#include "stdafx.h"
#include "fAxxeval8046.h"

inline int fAxxeval8046(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx257.data[0][0], 0, sizeof(bmats.Axx257.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx108, bmats.Axx1423, bmats.Axx1470, bmats.Axx1473, bmats.Axx1593, bmats.Axx1611, bmats.Axx1826, bmats.Axx2159, bmats.Axx3156, bmats.Axx317, bmats.Axx3220, bmats.Axx3380, bmats.Axx359, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx257, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
