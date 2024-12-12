#include "stdafx.h"
#include "fAxxeval7516.h"

inline int fAxxeval7516(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1632.data[0][0], 0, sizeof(bmats.Axx1632.data[0][0])*BL*BL);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx11, bmats.Axx1358, bmats.Axx1365, bmats.Axx2590, };
    double A_coeffs[4] = {1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1632, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
