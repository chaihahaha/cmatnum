#include "stdafx.h"
#include "fAxxeval6894.h"

inline int fAxxeval6894(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3273.data[0][0], 0, sizeof(bmats.Axx3273.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_22_20, bmats.Axx1115, bmats.Axx1570, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3273, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
