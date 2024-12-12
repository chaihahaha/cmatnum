#include "stdafx.h"
#include "fAxxeval4201.h"

inline int fAxxeval4201(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3046.data[0][0], 0, sizeof(bmats.Axx3046.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_28_13, bmats.Axx3041, bmats.Axx3045, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3046, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
