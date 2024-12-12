#include "stdafx.h"
#include "fAxxeval4615.h"

inline int fAxxeval4615(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3334.data[0][0], 0, sizeof(bmats.Axx3334.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx232, bmats.Axx3277, bmats.Axx3280, bmats.Axx3286, bmats.Axx3312, bmats.Axx3315, bmats.Axx3316, bmats.Axx3319, bmats.Axx3321, bmats.Axx3323, bmats.Axx3327, bmats.Axx3328, bmats.Axx3332, bmats.Axx984, bmats.Axx990, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3334, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
