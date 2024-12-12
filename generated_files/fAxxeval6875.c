#include "stdafx.h"
#include "fAxxeval6875.h"

inline int fAxxeval6875(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx866.data[0][0], 0, sizeof(bmats.Axx866.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_22_24, bmats.Axx657, bmats.Axx829, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx866, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
