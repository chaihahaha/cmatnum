#include "stdafx.h"
#include "fAxxeval6385.h"

inline int fAxxeval6385(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx773.data[0][0], 0, sizeof(bmats.Axx773.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1548, bmats.Axx1614, bmats.Axx1627, bmats.Axx1684, bmats.Axx1768, bmats.Axx1831, bmats.Axx1848, bmats.Axx1985, bmats.Axx27, bmats.Axx511, bmats.Axx621, bmats.Axx654, bmats.Axx676, bmats.Axx849, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx773, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
