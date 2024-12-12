#include "stdafx.h"
#include "fAxxeval3059.h"

inline int fAxxeval3059(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx579.data[0][0], 0, sizeof(bmats.Axx579.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_2_3, bmats.Axx719, bmats.Axx784, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx579, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
