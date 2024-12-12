#include "stdafx.h"
#include "fAxxeval5302.h"

inline int fAxxeval5302(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3309.data[0][0], 0, sizeof(bmats.Axx3309.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_9_23, bmats.Axx2114, bmats.Axx853, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx3309, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
