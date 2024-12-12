#include "stdafx.h"
#include "fAxxeval7346.h"

inline int fAxxeval7346(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx219.data[0][0], 0, sizeof(bmats.Axx219.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1198, bmats.Axx1301, bmats.Axx1315, bmats.Axx1330, bmats.Axx1348, bmats.Axx1837, bmats.Axx1993, bmats.Axx2568, bmats.Axx2979, bmats.Axx3003, bmats.Axx3291, bmats.Axx3326, bmats.Axx388, bmats.Axx912, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx219, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
