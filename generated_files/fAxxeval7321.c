#include "stdafx.h"
#include "fAxxeval7321.h"

inline int fAxxeval7321(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx994.data[0][0], 0, sizeof(bmats.Axx994.data[0][0])*BL*BL);
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.Axx1348, bmats.Axx1837, bmats.Axx1993, bmats.Axx2979, bmats.Axx3003, bmats.Axx3291, bmats.Axx3326, bmats.Axx388, };
    double A_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx994, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
