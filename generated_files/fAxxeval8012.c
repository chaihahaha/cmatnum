#include "stdafx.h"
#include "fAxxeval8012.h"

inline int fAxxeval8012(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3337.data[0][0], 0, sizeof(bmats.Axx3337.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_25_23, bmats.Axx1114, bmats.Axx2850, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3337, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
