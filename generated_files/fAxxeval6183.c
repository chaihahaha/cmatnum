#include "stdafx.h"
#include "fAxxeval6183.h"

inline int fAxxeval6183(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2891.data[0][0], 0, sizeof(bmats.Axx2891.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx134, bmats.Axx1529, bmats.Axx1546, bmats.Axx1990, bmats.Axx2153, bmats.Axx2169, bmats.Axx2208, bmats.Axx2476, bmats.Axx2602, bmats.Axx3206, bmats.Axx3242, bmats.Axx3244, bmats.Axx3268, bmats.Axx3369, bmats.Axx880, bmats.Axx995, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2891, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
