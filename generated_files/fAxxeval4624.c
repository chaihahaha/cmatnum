#include "stdafx.h"
#include "fAxxeval4624.h"

inline int fAxxeval4624(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3342.data[0][0], 0, sizeof(bmats.Axx3342.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2215, bmats.Axx2282, bmats.Axx2347, bmats.Axx2416, bmats.Axx2484, bmats.Axx2547, bmats.Axx2617, bmats.Axx2687, bmats.Axx2759, bmats.Axx2827, bmats.Axx2907, bmats.Axx2987, bmats.Axx3060, bmats.Axx3136, bmats.Axx3257, bmats.Axx3340, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3342, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
