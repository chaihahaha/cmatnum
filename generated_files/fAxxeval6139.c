#include "stdafx.h"
#include "fAxxeval6139.h"

inline int fAxxeval6139(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1797.data[0][0], 0, sizeof(bmats.Axx1797.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1014, bmats.Axx1492, bmats.Axx1682, bmats.Axx1737, bmats.Axx1871, bmats.Axx1904, bmats.Axx201, bmats.Axx2099, bmats.Axx2234, bmats.Axx2819, bmats.Axx2970, bmats.Axx3086, bmats.Axx3309, bmats.Axx3383, bmats.Axx412, bmats.Axx998, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1797, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
