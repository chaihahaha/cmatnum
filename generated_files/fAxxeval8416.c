#include "stdafx.h"
#include "fAxxeval8416.h"

inline int fAxxeval8416(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx620.data[0][0], 0, sizeof(bmats.Axx620.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1174, bmats.Axx1178, bmats.Axx1301, bmats.Axx1719, bmats.Axx1992, bmats.Axx223, bmats.Axx224, bmats.Axx278, bmats.Axx2962, bmats.Axx572, bmats.Axx789, bmats.Axx790, bmats.Axx818, bmats.Axx825, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx620, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
