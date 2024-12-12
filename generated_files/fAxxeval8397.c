#include "stdafx.h"
#include "fAxxeval8397.h"

inline int fAxxeval8397(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2207.data[0][0], 0, sizeof(bmats.Axx2207.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1017, bmats.Axx143, bmats.Axx1691, bmats.Axx1720, bmats.Axx1744, bmats.Axx2218, bmats.Axx2767, bmats.Axx2888, bmats.Axx2965, bmats.Axx3042, bmats.Axx3193, bmats.Axx566, bmats.Axx606, bmats.Axx65, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2207, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
