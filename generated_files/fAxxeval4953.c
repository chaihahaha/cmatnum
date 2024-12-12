#include "stdafx.h"
#include "fAxxeval4953.h"

inline int fAxxeval4953(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx412.data[0][0], 0, sizeof(bmats.Axx412.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_4_23, bmats.Axx147, bmats.Axx534, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx412, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
