#include "stdafx.h"
#include "fAxxeval4512.h"

inline int fAxxeval4512(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx825.data[0][0], 0, sizeof(bmats.Axx825.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_16_13, bmats.Axx434, bmats.Axx812, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx825, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
