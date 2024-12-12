#include "stdafx.h"
#include "fAxxeval7525.h"

inline int fAxxeval7525(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx578.data[0][0], 0, sizeof(bmats.Axx578.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_26_32, bmats.Axx1362, bmats.Axx453, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx578, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
