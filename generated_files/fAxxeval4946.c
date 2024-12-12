#include "stdafx.h"
#include "fAxxeval4946.h"

inline int fAxxeval4946(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3393.data[0][0], 0, sizeof(bmats.Axx3393.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_4_22, bmats.Axx3016, bmats.Axx3388, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx3393, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
