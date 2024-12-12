#include "stdafx.h"
#include "fAxxeval2093.h"

inline int fAxxeval2093(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx475.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1800, bmats.Axx1814, bmats.Axx465, bmats.Axx466, bmats.Axx467, bmats.Axx470, bmats.Axx471, bmats.Axx472, bmats.Axx473, bmats.Axx474, bmats.Axx476, bmats.Axx544, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx475, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
