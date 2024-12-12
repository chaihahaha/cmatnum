#include "stdafx.h"
#include "fAxxeval4450.h"

inline int fAxxeval4450(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3259.data[0][0], 0, sizeof(bmats.Axx3259.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1309, bmats.Axx3258, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx3259, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
