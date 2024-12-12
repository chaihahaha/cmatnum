#include "stdafx.h"
#include "fAxxeval4695.h"

inline int fAxxeval4695(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3379.data[0][0], 0, sizeof(bmats.Axx3379.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2201, bmats.Axx2267, bmats.Axx2338, bmats.Axx2404, bmats.Axx2470, bmats.Axx2537, bmats.Axx2598, bmats.Axx2674, bmats.Axx2748, bmats.Axx2818, bmats.Axx2888, bmats.Axx2968, bmats.Axx3046, bmats.Axx3123, bmats.Axx3194, bmats.Axx3374, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3379, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
