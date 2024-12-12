#include "stdafx.h"
#include "fAxxeval2102.h"

inline int fAxxeval2102(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1795.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx445, bmats.Axx446, bmats.Axx448, bmats.Axx449, bmats.Axx452, bmats.Axx453, bmats.Axx455, bmats.Axx456, bmats.Axx459, bmats.Axx460, bmats.Axx466, bmats.Axx501, bmats.Axx502, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1795, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
