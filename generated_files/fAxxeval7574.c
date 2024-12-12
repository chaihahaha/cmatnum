#include "stdafx.h"
#include "fAxxeval7574.h"

inline int fAxxeval7574(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3089.data[0][0], 0, sizeof(bmats.Axx3089.data[0][0])*BL*BL);
    int n_A_mats = 8;
    double_cmat A_mats[8] = {bmats.Axx1404, bmats.Axx1407, bmats.Axx145, bmats.Axx1631, bmats.Axx1905, bmats.Axx2464, bmats.Axx376, bmats.Axx535, };
    double A_coeffs[8] = {1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3089, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
