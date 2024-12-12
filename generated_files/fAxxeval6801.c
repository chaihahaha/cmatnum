#include "stdafx.h"
#include "fAxxeval6801.h"

inline int fAxxeval6801(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx392.data[0][0], 0, sizeof(bmats.Axx392.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx3210, bmats.Axx403, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx392, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
