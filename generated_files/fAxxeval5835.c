#include "stdafx.h"
#include "fAxxeval5835.h"

inline int fAxxeval5835(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx664.data[0][0], 0, sizeof(bmats.Axx664.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_12_20, bmats.Axx1008, bmats.Axx2045, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx664, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
