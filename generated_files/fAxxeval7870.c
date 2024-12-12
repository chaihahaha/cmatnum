#include "stdafx.h"
#include "fAxxeval7870.h"

inline int fAxxeval7870(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1996.data[0][0], 0, sizeof(bmats.Axx1996.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx104, bmats.Axx1256, bmats.Axx1341, bmats.Axx1453, bmats.Axx1850, bmats.Axx2232, bmats.Axx2634, bmats.Axx2758, bmats.Axx2873, bmats.Axx3412, bmats.Axx443, bmats.Axx459, bmats.Axx724, bmats.Axx739, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1996, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
