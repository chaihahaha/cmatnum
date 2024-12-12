#include "stdafx.h"
#include "fAxxeval1907.h"

inline int fAxxeval1907(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1725.data[0][0], 0, sizeof(bmats.Axx1725.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_30_29, bmats.Axx1713, bmats.Axx1724, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1725, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
