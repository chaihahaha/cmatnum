#include "stdafx.h"
#include "fAxxeval4680.h"

inline int fAxxeval4680(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3376.data[0][0], 0, sizeof(bmats.Axx3376.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2200, bmats.Axx2266, bmats.Axx2337, bmats.Axx2403, bmats.Axx2469, bmats.Axx2536, bmats.Axx2597, bmats.Axx2673, bmats.Axx2747, bmats.Axx2817, bmats.Axx2887, bmats.Axx2967, bmats.Axx3045, bmats.Axx3122, bmats.Axx3193, bmats.Axx3375, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3376, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
