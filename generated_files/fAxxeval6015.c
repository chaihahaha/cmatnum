#include "stdafx.h"
#include "fAxxeval6015.h"

inline int fAxxeval6015(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3303.data[0][0], 0, sizeof(bmats.Axx3303.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx2502, bmats.Axx374, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx3303, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
