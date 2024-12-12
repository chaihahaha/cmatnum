#include "stdafx.h"
#include "fAxxeval7038.h"

inline int fAxxeval7038(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx985.data[0][0], 0, sizeof(bmats.Axx985.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1193, bmats.Axx1206, bmats.Axx1213, bmats.Axx1225, bmats.Axx1230, bmats.Axx1233, bmats.Axx1237, bmats.Axx1567, bmats.Axx2545, bmats.Axx2849, bmats.Axx342, bmats.Axx845, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx985, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
