#include "stdafx.h"
#include "fAxxeval5775.h"

inline int fAxxeval5775(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2018.data[0][0], 0, sizeof(bmats.Axx2018.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_13_32, bmats.Axx1820, bmats.Axx2644, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2018, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
