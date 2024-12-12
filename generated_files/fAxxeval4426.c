#include "stdafx.h"
#include "fAxxeval4426.h"

inline int fAxxeval4426(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3239.data[0][0], 0, sizeof(bmats.Axx3239.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_31_16, bmats.Axx3187, bmats.Axx3238, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3239, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
