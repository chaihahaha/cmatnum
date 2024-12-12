#include "stdafx.h"
#include "fAxxeval2889.h"

inline int fAxxeval2889(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx844.data[0][0], 0, sizeof(bmats.Axx844.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx2105, bmats.Axx433, bmats.Axx434, bmats.Axx497, bmats.Axx557, bmats.Axx610, bmats.Axx656, bmats.Axx700, bmats.Axx815, bmats.Axx831, bmats.Axx835, bmats.Axx837, bmats.Axx853, bmats.Axx863, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx844, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
