#include "stdafx.h"
#include "fAxxeval3055.h"

inline int fAxxeval3055(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx691.data[0][0], 0, sizeof(bmats.Axx691.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_2_4, bmats.Axx523, bmats.Axx784, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx691, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
