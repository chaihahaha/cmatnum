#include "stdafx.h"
#include "fAxxeval5951.h"

inline int fAxxeval5951(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1654.data[0][0], 0, sizeof(bmats.Axx1654.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_11_32, bmats.Axx2166, bmats.Axx2676, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1654, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
