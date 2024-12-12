#include "stdafx.h"
#include "fAxxeval7668.h"

inline int fAxxeval7668(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1551.data[0][0], 0, sizeof(bmats.Axx1551.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_17_20, bmats.Axx1408, bmats.Axx1664, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1551, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
