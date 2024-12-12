#include "stdafx.h"
#include "fAxxeval2691.h"

inline int fAxxeval2691(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx729.data[0][0], 0, sizeof(bmats.Axx729.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_7_8, bmats.Axx2076, bmats.Axx763, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx729, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
