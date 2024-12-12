#include "stdafx.h"
#include "fAxxeval7415.h"

inline int fAxxeval7415(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3194.data[0][0], 0, sizeof(bmats.Axx3194.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1198, bmats.Axx1301, bmats.Axx1309, bmats.Axx1330, bmats.Axx1837, bmats.Axx1993, bmats.Axx2568, bmats.Axx2979, bmats.Axx3003, bmats.Axx3291, bmats.Axx3326, bmats.Axx388, bmats.Axx912, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3194, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
