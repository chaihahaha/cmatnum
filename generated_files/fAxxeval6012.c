#include "stdafx.h"
#include "fAxxeval6012.h"

inline int fAxxeval6012(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx374.data[0][0], 0, sizeof(bmats.Axx374.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_16_20, bmats.Axx2033, bmats.Axx2644, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx374, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
