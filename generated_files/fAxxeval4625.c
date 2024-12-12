#include "stdafx.h"
#include "fAxxeval4625.h"

inline int fAxxeval4625(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3343.data[0][0], 0, sizeof(bmats.Axx3343.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2214, bmats.Axx2281, bmats.Axx2346, bmats.Axx2415, bmats.Axx2483, bmats.Axx2546, bmats.Axx2616, bmats.Axx2686, bmats.Axx2758, bmats.Axx2826, bmats.Axx2906, bmats.Axx2986, bmats.Axx3059, bmats.Axx3135, bmats.Axx3258, bmats.Axx3341, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3343, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
