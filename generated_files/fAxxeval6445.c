#include "stdafx.h"
#include "fAxxeval6445.h"

inline int fAxxeval6445(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2899.data[0][0], 0, sizeof(bmats.Axx2899.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_14_7, bmats.Axx2676, bmats.Axx905, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2899, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
