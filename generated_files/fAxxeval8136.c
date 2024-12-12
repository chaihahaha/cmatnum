#include "stdafx.h"
#include "fAxxeval8136.h"

inline int fAxxeval8136(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx537.data[0][0], 0, sizeof(bmats.Axx537.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_28_30, bmats.Axx177, bmats.Axx2947, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx537, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
