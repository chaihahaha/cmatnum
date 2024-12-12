#include "stdafx.h"
#include "fAxxeval6712.h"

inline int fAxxeval6712(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx556.data[0][0], 0, sizeof(bmats.Axx556.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1111, bmats.Axx1113, bmats.Axx136, bmats.Axx1645, bmats.Axx174, bmats.Axx1830, bmats.Axx1866, bmats.Axx2056, bmats.Axx2112, bmats.Axx227, bmats.Axx2825, bmats.Axx3322, bmats.Axx684, bmats.Axx978, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx556, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
