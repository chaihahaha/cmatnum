#include "stdafx.h"
#include "fAxxeval2590.h"

inline int fAxxeval2590(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1628.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx488, bmats.Axx489, bmats.Axx602, bmats.Axx603, bmats.Axx695, bmats.Axx696, bmats.Axx708, bmats.Axx709, bmats.Axx712, bmats.Axx713, bmats.Axx721, bmats.Axx747, bmats.Axx748, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1628, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
