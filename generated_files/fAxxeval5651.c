#include "stdafx.h"
#include "fAxxeval5651.h"

inline int fAxxeval5651(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1670.data[0][0], 0, sizeof(bmats.Axx1670.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_14_19, bmats.Axx2074, bmats.Axx3278, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1670, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
