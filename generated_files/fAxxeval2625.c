#include "stdafx.h"
#include "fAxxeval2625.h"

inline int fAxxeval2625(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx549.data[0][0], 0, sizeof(bmats.Axx549.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_8_14, bmats.Axx724, bmats.Axx729, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx549, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}