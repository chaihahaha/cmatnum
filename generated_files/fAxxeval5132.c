#include "stdafx.h"
#include "fAxxeval5132.h"

inline int fAxxeval5132(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3198.data[0][0], 0, sizeof(bmats.Axx3198.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_2_25, bmats.Axx2371, bmats.Axx3251, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx3198, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}