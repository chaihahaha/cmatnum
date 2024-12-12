#include "stdafx.h"
#include "fAxxeval1837.h"

inline int fAxxeval1837(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx233.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1684, bmats.Axx236, bmats.Axx237, bmats.Axx242, bmats.Axx243, bmats.Axx249, bmats.Axx250, bmats.Axx253, bmats.Axx254, bmats.Axx257, bmats.Axx258, bmats.Axx297, bmats.Axx298, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx233, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
