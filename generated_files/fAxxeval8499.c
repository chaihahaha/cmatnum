#include "stdafx.h"
#include "fAxxeval8499.h"

inline int fAxxeval8499(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1520.data[0][0], 0, sizeof(bmats.Axx1520.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1010, bmats.Axx1296, bmats.Axx1551, bmats.Axx1569, bmats.Axx1716, bmats.Axx1913, bmats.Axx2052, bmats.Axx2485, bmats.Axx2797, bmats.Axx280, bmats.Axx3273, bmats.Axx715, bmats.Axx73, bmats.Axx902, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1520, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
