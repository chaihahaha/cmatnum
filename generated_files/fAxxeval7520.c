#include "stdafx.h"
#include "fAxxeval7520.h"

inline int fAxxeval7520(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3345.data[0][0], 0, sizeof(bmats.Axx3345.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1042, bmats.Axx1043, bmats.Axx1127, bmats.Axx1192, bmats.Axx1250, bmats.Axx1299, bmats.Axx1345, bmats.Axx1367, bmats.Axx1370, bmats.Axx1393, bmats.Axx2288, bmats.Axx348, bmats.Axx349, bmats.Axx906, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3345, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}