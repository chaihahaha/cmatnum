#include "stdafx.h"
#include "fAxxeval6471.h"

inline int fAxxeval6471(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2129.data[0][0], 0, sizeof(bmats.Axx2129.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1587, bmats.Axx1606, bmats.Axx1779, bmats.Axx1792, bmats.Axx1841, bmats.Axx1882, bmats.Axx1931, bmats.Axx1937, bmats.Axx2019, bmats.Axx2162, bmats.Axx436, bmats.Axx507, bmats.Axx695, bmats.Axx741, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2129, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}