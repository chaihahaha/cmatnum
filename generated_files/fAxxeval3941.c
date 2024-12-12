#include "stdafx.h"
#include "fAxxeval3941.h"

inline int fAxxeval3941(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2818.data[0][0], 0, sizeof(bmats.Axx2818.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_23_13, bmats.Axx2813, bmats.Axx2817, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2818, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
