#include "stdafx.h"
#include "fAxxeval5093.h"

inline int fAxxeval5093(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1521.data[0][0], 0, sizeof(bmats.Axx1521.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_2_29, bmats.Axx3085, bmats.Axx673, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1521, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
