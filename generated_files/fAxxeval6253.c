#include "stdafx.h"
#include "fAxxeval6253.h"

inline int fAxxeval6253(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2026.data[0][0], 0, sizeof(bmats.Axx2026.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1488, bmats.Axx1502, bmats.Axx1609, bmats.Axx1735, bmats.Axx1748, bmats.Axx1825, bmats.Axx198, bmats.Axx2046, bmats.Axx2931, bmats.Axx308, bmats.Axx3199, bmats.Axx3390, bmats.Axx532, bmats.Axx568, bmats.Axx853, bmats.Axx897, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2026, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
