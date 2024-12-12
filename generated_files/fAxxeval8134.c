#include "stdafx.h"
#include "fAxxeval8134.h"

inline int fAxxeval8134(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3195.data[0][0], 0, sizeof(bmats.Axx3195.data[0][0])*BL*BL);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1476, bmats.Axx257, bmats.Axx527, bmats.Axx937, };
    double A_coeffs[4] = {1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3195, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
