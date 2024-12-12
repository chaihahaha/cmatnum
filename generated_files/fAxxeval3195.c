#include "stdafx.h"
#include "fAxxeval3195.h"

inline int fAxxeval3195(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx940.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1685, bmats.Axx180, bmats.Axx1875, bmats.Axx2165, bmats.Axx298, bmats.Axx4, bmats.Axx523, bmats.Axx569, bmats.Axx57, bmats.Axx855, bmats.Axx901, bmats.Axx908, bmats.Axx943, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx940, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
