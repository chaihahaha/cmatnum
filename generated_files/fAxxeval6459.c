#include "stdafx.h"
#include "fAxxeval6459.h"

inline int fAxxeval6459(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2824.data[0][0], 0, sizeof(bmats.Axx2824.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1584, bmats.Axx1787, bmats.Axx1838, bmats.Axx1926, bmats.Axx1943, bmats.Axx206, bmats.Axx2081, bmats.Axx2098, bmats.Axx2105, bmats.Axx488, bmats.Axx502, bmats.Axx513, bmats.Axx651, bmats.Axx666, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2824, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}