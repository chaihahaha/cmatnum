#include "stdafx.h"
#include "fAxxeval6899.h"

inline int fAxxeval6899(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3327.data[0][0], 0, sizeof(bmats.Axx3327.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_21_29, };
    double A_coeffs[1] = {-1, };
    matlincomb_double_contiguous(bmats.Axx3327, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
