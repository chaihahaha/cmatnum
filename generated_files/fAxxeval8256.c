#include "stdafx.h"
#include "fAxxeval8256.h"

inline int fAxxeval8256(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx621.data[0][0], 0, sizeof(bmats.Axx621.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx656, bmats.Axx955, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx621, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
