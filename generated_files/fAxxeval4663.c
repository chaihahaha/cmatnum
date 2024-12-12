#include "stdafx.h"
#include "fAxxeval4663.h"

inline int fAxxeval4663(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3370.data[0][0], 0, sizeof(bmats.Axx3370.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2233, bmats.Axx2301, bmats.Axx2368, bmats.Axx2435, bmats.Axx2503, bmats.Axx2565, bmats.Axx2635, bmats.Axx2709, bmats.Axx2780, bmats.Axx2850, bmats.Axx2925, bmats.Axx3005, bmats.Axx3083, bmats.Axx3159, bmats.Axx3239, bmats.Axx3368, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3370, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
