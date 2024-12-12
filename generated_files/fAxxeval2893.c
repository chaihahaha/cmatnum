#include "stdafx.h"
#include "fAxxeval2893.h"

inline int fAxxeval2893(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx849.data[0][0], 0, sizeof(bmats.Axx849.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_12_2, bmats.Axx2111, bmats.Axx831, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx849, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
