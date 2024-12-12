#include "stdafx.h"
#include "fAxxeval6436.h"

inline int fAxxeval6436(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1590.data[0][0], 0, sizeof(bmats.Axx1590.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_14_8, bmats.Axx795, bmats.Axx905, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1590, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
