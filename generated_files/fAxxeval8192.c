#include "stdafx.h"
#include "fAxxeval8192.h"

inline int fAxxeval8192(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx425.data[0][0], 0, sizeof(bmats.Axx425.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1035, bmats.Axx1167, bmats.Axx1383, bmats.Axx1484, bmats.Axx167, bmats.Axx1839, bmats.Axx1947, bmats.Axx2529, bmats.Axx2741, bmats.Axx2977, bmats.Axx3106, bmats.Axx3381, bmats.Axx753, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx425, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
