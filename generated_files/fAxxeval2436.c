#include "stdafx.h"
#include "fAxxeval2436.h"

inline int fAxxeval2436(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx620.data[0][0], 0, sizeof(bmats.Axx620.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1945, bmats.Axx645, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx620, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
