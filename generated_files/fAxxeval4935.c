#include "stdafx.h"
#include "fAxxeval4935.h"

inline int fAxxeval4935(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1986.data[0][0], 0, sizeof(bmats.Axx1986.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_4_17, bmats.Axx538, bmats.Axx992, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx1986, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
