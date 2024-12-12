#include "stdafx.h"
#include "fAxxeval4481.h"

inline int fAxxeval4481(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx174.data[0][0], 0, sizeof(bmats.Axx174.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_16_6, bmats.Axx1541, bmats.Axx19, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx174, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
