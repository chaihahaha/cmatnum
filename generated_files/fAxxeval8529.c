#include "stdafx.h"
#include "fAxxeval8529.h"

inline int fAxxeval8529(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1997.data[0][0], 0, sizeof(bmats.Axx1997.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1039, bmats.Axx1085, bmats.Axx1283, bmats.Axx1624, bmats.Axx2041, bmats.Axx2675, bmats.Axx2779, bmats.Axx283, bmats.Axx402, bmats.Axx437, bmats.Axx539, bmats.Axx871, bmats.Axx970, bmats.Axx991, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1997, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
