#include "stdafx.h"
#include "fAxxeval1180.h"

inline int fAxxeval1180(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1181.data[0][0], 0, sizeof(bmats.Axx1181.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_21_32, };
    double A_coeffs[1] = {16, };
    matlincomb_double_contiguous(bmats.Axx1181, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
