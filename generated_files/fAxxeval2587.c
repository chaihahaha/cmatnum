#include "stdafx.h"
#include "fAxxeval2587.h"

inline int fAxxeval2587(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx723.data[0][0], 0, sizeof(bmats.Axx723.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1628, bmats.Axx488, bmats.Axx489, bmats.Axx695, bmats.Axx696, bmats.Axx708, bmats.Axx709, bmats.Axx712, bmats.Axx713, bmats.Axx716, bmats.Axx717, bmats.Axx721, bmats.Axx747, bmats.Axx748, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx723, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}