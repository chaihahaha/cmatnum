#include "stdafx.h"
#include "fAxxeval7667.h"

inline int fAxxeval7667(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3403.data[0][0], 0, sizeof(bmats.Axx3403.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_17_19, bmats.Axx1406, bmats.Axx1664, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3403, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
