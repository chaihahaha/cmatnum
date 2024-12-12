#include "stdafx.h"
#include "fAxxeval1805.h"

inline int fAxxeval1805(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1600.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1650, bmats.Axx1652, bmats.Axx1654, bmats.Axx1657, bmats.Axx1658, bmats.Axx238, bmats.Axx240, bmats.Axx244, bmats.Axx248, bmats.Axx276, bmats.Axx279, bmats.Axx282, bmats.Axx285, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1600, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
