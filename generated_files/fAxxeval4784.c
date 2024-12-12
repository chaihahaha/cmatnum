#include "stdafx.h"
#include "fAxxeval4784.h"

inline int fAxxeval4784(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx880.data[0][0], 0, sizeof(bmats.Axx880.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_1_27, bmats.Axx191, bmats.Axx3400, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx880, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
