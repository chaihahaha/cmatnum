#include "stdafx.h"
#include "fAxxeval259.h"

inline int fAxxeval259(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx260.data[0][0], 0, sizeof(bmats.Axx260.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_29_23, };
    double A_coeffs[1] = {17, };
    matlincomb_double_contiguous(bmats.Axx260, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
