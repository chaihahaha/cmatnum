#include "stdafx.h"
#include "fAxxeval2509.h"

inline int fAxxeval2509(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx402.data[0][0], 0, sizeof(bmats.Axx402.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_9_10, bmats.Axx1983, bmats.Axx2000, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx402, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
