#include "stdafx.h"
#include "fAxxeval7307.h"

inline int fAxxeval7307(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx539.data[0][0], 0, sizeof(bmats.Axx539.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_19_17, bmats.Axx1281, bmats.Axx2401, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx539, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
