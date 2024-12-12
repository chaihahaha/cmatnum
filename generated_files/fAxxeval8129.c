#include "stdafx.h"
#include "fAxxeval8129.h"

inline int fAxxeval8129(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx915.data[0][0], 0, sizeof(bmats.Axx915.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1038, bmats.Axx1140, bmats.Axx1205, bmats.Axx1258, bmats.Axx1308, bmats.Axx1380, bmats.Axx1446, bmats.Axx1463, bmats.Axx1469, bmats.Axx1930, bmats.Axx291, bmats.Axx362, bmats.Axx563, bmats.Axx939, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx915, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
