#include "stdafx.h"
#include "fAxxeval7853.h"

inline int fAxxeval7853(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2968.data[0][0], 0, sizeof(bmats.Axx2968.data[0][0])*BL*BL);
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.Axx1256, bmats.Axx1341, bmats.Axx1419, bmats.Axx1453, bmats.Axx1850, bmats.Axx2634, bmats.Axx2758, bmats.Axx2873, bmats.Axx459, bmats.Axx724, bmats.Axx739, };
    double A_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2968, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
