#include "stdafx.h"
#include "fAxxeval2174.h"

inline int fAxxeval2174(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1861.data[0][0], 0, sizeof(bmats.Axx1861.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1859, bmats.Axx506, bmats.Axx528, bmats.Axx529, bmats.Axx530, bmats.Axx531, bmats.Axx532, bmats.Axx533, bmats.Axx534, bmats.Axx535, bmats.Axx536, bmats.Axx537, bmats.Axx538, bmats.Axx539, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1861, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
