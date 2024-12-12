#include "stdafx.h"
#include "fAxxeval7523.h"

inline int fAxxeval7523(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx878.data[0][0], 0, sizeof(bmats.Axx878.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_26_29, bmats.Axx1363, bmats.Axx783, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx878, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
