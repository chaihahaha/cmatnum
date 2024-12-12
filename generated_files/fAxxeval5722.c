#include "stdafx.h"
#include "fAxxeval5722.h"

inline int fAxxeval5722(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx805.data[0][0], 0, sizeof(bmats.Axx805.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_13_29, bmats.Axx1009, bmats.Axx2542, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx805, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
