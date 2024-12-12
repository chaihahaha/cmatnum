#include "stdafx.h"
#include "fAxxeval2420.h"

inline int fAxxeval2420(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1947.data[0][0], 0, sizeof(bmats.Axx1947.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_10_10, bmats.Axx525, bmats.Axx620, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx1947, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
