#include "stdafx.h"
#include "fAxxeval3082.h"

inline int fAxxeval3082(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx784.data[0][0], 0, sizeof(bmats.Axx784.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_2_10, bmats.Axx180, bmats.Axx895, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx784, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
