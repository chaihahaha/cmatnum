#include "stdafx.h"
#include "fAxxeval5998.h"

inline int fAxxeval5998(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx152.data[0][0], 0, sizeof(bmats.Axx152.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1020, bmats.Axx1660, bmats.Axx1713, bmats.Axx1858, bmats.Axx2068, bmats.Axx211, bmats.Axx240, bmats.Axx248, bmats.Axx285, bmats.Axx3047, bmats.Axx3126, bmats.Axx3247, bmats.Axx3372, bmats.Axx793, bmats.Axx898, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx152, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}