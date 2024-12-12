#include "stdafx.h"
#include "fAxxeval2850.h"

inline int fAxxeval2850(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2136.data[0][0], 0, sizeof(bmats.Axx2136.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx2130, bmats.Axx834, bmats.Axx842, bmats.Axx843, bmats.Axx844, bmats.Axx845, bmats.Axx846, bmats.Axx847, bmats.Axx850, bmats.Axx851, bmats.Axx852, bmats.Axx853, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2136, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
