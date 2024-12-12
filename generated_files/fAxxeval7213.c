#include "stdafx.h"
#include "fAxxeval7213.h"

inline int fAxxeval7213(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3405.data[0][0], 0, sizeof(bmats.Axx3405.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx2486, bmats.Axx671, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx3405, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
