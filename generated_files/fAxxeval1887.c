#include "stdafx.h"
#include "fAxxeval1887.h"

inline int fAxxeval1887(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx307.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1662, bmats.Axx1706, bmats.Axx295, bmats.Axx301, bmats.Axx305, bmats.Axx310, bmats.Axx313, bmats.Axx315, bmats.Axx317, bmats.Axx319, bmats.Axx321, bmats.Axx323, bmats.Axx325, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx307, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
