#include "stdafx.h"
#include "fAxxeval4830.h"

inline int fAxxeval4830(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1948.data[0][0], 0, sizeof(bmats.Axx1948.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_5_29, bmats.Axx1986, bmats.Axx3406, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1948, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
