#include "stdafx.h"
#include "fAxxeval2186.h"

inline int fAxxeval2186(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx538.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1853, bmats.Axx1859, bmats.Axx506, bmats.Axx528, bmats.Axx529, bmats.Axx530, bmats.Axx533, bmats.Axx534, bmats.Axx535, bmats.Axx536, bmats.Axx537, bmats.Axx539, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx538, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
