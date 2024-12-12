#include "stdafx.h"
#include "fAxxeval4417.h"

inline int fAxxeval4417(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3231.data[0][0], 0, sizeof(bmats.Axx3231.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_31_3, bmats.Axx3186, bmats.Axx3230, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3231, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
