#include "stdafx.h"
#include "fAxxeval2899.h"

inline int fAxxeval2899(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx826.data[0][0], 0, sizeof(bmats.Axx826.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_12_7, bmats.Axx191, bmats.Axx739, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx826, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}