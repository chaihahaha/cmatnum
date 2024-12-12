#include "stdafx.h"
#include "fAxxeval8150.h"

inline int fAxxeval8150(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1680.data[0][0], 0, sizeof(bmats.Axx1680.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx122, bmats.Axx1540, bmats.Axx1701, bmats.Axx1715, bmats.Axx1911, bmats.Axx2549, bmats.Axx288, bmats.Axx3045, bmats.Axx3247, bmats.Axx3375, bmats.Axx460, bmats.Axx610, bmats.Axx632, bmats.Axx776, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1680, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
