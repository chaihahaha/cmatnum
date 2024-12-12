#include "stdafx.h"
#include "fAxxeval7838.h"

inline int fAxxeval7838(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2679.data[0][0], 0, sizeof(bmats.Axx2679.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_24_18, bmats.Axx1416, bmats.Axx2231, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2679, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
