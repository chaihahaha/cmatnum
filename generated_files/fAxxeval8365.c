#include "stdafx.h"
#include "fAxxeval8365.h"

inline int fAxxeval8365(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx842.data[0][0], 0, sizeof(bmats.Axx842.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1304, bmats.Axx1534, bmats.Axx1700, bmats.Axx1781, bmats.Axx1794, bmats.Axx1902, bmats.Axx2651, bmats.Axx281, bmats.Axx2859, bmats.Axx2896, bmats.Axx3277, bmats.Axx398, bmats.Axx857, bmats.Axx878, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx842, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}