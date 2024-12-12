#include "stdafx.h"
#include "fAxxeval6023.h"

inline int fAxxeval6023(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx550.data[0][0], 0, sizeof(bmats.Axx550.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_16_24, bmats.Axx2374, bmats.Axx748, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx550, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
