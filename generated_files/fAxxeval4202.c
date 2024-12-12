#include "stdafx.h"
#include "fAxxeval4202.h"

inline int fAxxeval4202(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3047.data[0][0], 0, sizeof(bmats.Axx3047.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx303, bmats.Axx3046, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx3047, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
