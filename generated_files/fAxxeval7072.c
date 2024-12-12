#include "stdafx.h"
#include "fAxxeval7072.h"

inline int fAxxeval7072(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1923.data[0][0], 0, sizeof(bmats.Axx1923.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1193, bmats.Axx1206, bmats.Axx1213, bmats.Axx1225, bmats.Axx1230, bmats.Axx1233, bmats.Axx1237, bmats.Axx1567, bmats.Axx1684, bmats.Axx2545, bmats.Axx264, bmats.Axx2849, bmats.Axx845, bmats.Axx917, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1923, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
