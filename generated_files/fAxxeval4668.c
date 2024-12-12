#include "stdafx.h"
#include "fAxxeval4668.h"

inline int fAxxeval4668(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3372.data[0][0], 0, sizeof(bmats.Axx3372.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2232, bmats.Axx2300, bmats.Axx2367, bmats.Axx2434, bmats.Axx2502, bmats.Axx2564, bmats.Axx2634, bmats.Axx2708, bmats.Axx2779, bmats.Axx2849, bmats.Axx2924, bmats.Axx3004, bmats.Axx3082, bmats.Axx3158, bmats.Axx3238, bmats.Axx3367, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3372, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
