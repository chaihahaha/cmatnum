#include "stdafx.h"
#include "fAxxeval7319.h"

inline int fAxxeval7319(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx868.data[0][0], 0, sizeof(bmats.Axx868.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1198, bmats.Axx1301, bmats.Axx1309, bmats.Axx1330, bmats.Axx1348, bmats.Axx1837, bmats.Axx1993, bmats.Axx2979, bmats.Axx3003, bmats.Axx3291, bmats.Axx3326, bmats.Axx388, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx868, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
