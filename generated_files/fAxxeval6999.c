#include "stdafx.h"
#include "fAxxeval6999.h"

inline int fAxxeval6999(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx676.data[0][0], 0, sizeof(bmats.Axx676.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_21_30, bmats.Axx2265, bmats.Axx2851, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx676, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
