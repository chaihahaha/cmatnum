#include "stdafx.h"
#include "fAxxeval2692.h"

inline int fAxxeval2692(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1827.data[0][0], 0, sizeof(bmats.Axx1827.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx763, bmats.Axx768, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx1827, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
