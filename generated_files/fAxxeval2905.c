#include "stdafx.h"
#include "fAxxeval2905.h"

inline int fAxxeval2905(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx713.data[0][0], 0, sizeof(bmats.Axx713.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_12_9, bmats.Axx130, bmats.Axx2140, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx713, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}