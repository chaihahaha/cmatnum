#include "stdafx.h"
#include "fAxxeval8164.h"

inline int fAxxeval8164(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1617.data[0][0], 0, sizeof(bmats.Axx1617.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1721, bmats.Axx2621, bmats.Axx2623, bmats.Axx284, bmats.Axx2904, bmats.Axx311, bmats.Axx3114, bmats.Axx542, bmats.Axx69, bmats.Axx745, bmats.Axx784, bmats.Axx864, bmats.Axx866, bmats.Axx964, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1617, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
