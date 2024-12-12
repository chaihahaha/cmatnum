#include "stdafx.h"
#include "fAxxeval4652.h"

inline int fAxxeval4652(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3366.data[0][0], 0, sizeof(bmats.Axx3366.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2231, bmats.Axx2297, bmats.Axx2366, bmats.Axx2432, bmats.Axx2500, bmats.Axx2562, bmats.Axx2632, bmats.Axx2707, bmats.Axx2778, bmats.Axx2847, bmats.Axx2922, bmats.Axx3003, bmats.Axx3081, bmats.Axx3156, bmats.Axx3228, bmats.Axx3364, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3366, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
