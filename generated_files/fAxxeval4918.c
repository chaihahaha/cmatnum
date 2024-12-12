#include "stdafx.h"
#include "fAxxeval4918.h"

inline int fAxxeval4918(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx796.data[0][0], 0, sizeof(bmats.Axx796.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_4_29, bmats.Axx3400, bmats.Axx994, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx796, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
