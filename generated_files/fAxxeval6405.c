#include "stdafx.h"
#include "fAxxeval6405.h"

inline int fAxxeval6405(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx767.data[0][0], 0, sizeof(bmats.Axx767.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1575, bmats.Axx1632, bmats.Axx1771, bmats.Axx1812, bmats.Axx2044, bmats.Axx2073, bmats.Axx2090, bmats.Axx21, bmats.Axx445, bmats.Axx448, bmats.Axx460, bmats.Axx492, bmats.Axx837, bmats.Axx868, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx767, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
