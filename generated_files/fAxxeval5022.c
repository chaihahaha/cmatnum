#include "stdafx.h"
#include "fAxxeval5022.h"

inline int fAxxeval5022(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx593.data[0][0], 0, sizeof(bmats.Axx593.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_3_17, bmats.Axx1695, bmats.Axx1705, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx593, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
