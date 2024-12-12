#include "stdafx.h"
#include "fAxxeval2660.h"

inline int fAxxeval2660(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2081.data[0][0], 0, sizeof(bmats.Axx2081.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx2078, bmats.Axx425, bmats.Axx426, bmats.Axx600, bmats.Axx651, bmats.Axx693, bmats.Axx728, bmats.Axx733, bmats.Axx751, bmats.Axx753, bmats.Axx755, bmats.Axx757, bmats.Axx759, bmats.Axx789, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2081, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
