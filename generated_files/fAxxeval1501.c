#include "stdafx.h"
#include "fAxxeval1501.h"

inline int fAxxeval1501(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1502.data[0][0], 0, sizeof(bmats.Axx1502.data[0][0])*BL*BL);
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.Axx1486, bmats.Axx1489, bmats.Axx1490, bmats.Axx1492, bmats.Axx1493, bmats.Axx1496, bmats.Axx1498, bmats.Axx1499, bmats.Axx64, bmats.Axx69, bmats.Axx72, };
    double A_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1502, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
