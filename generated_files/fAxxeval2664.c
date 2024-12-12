#include "stdafx.h"
#include "fAxxeval2664.h"

inline int fAxxeval2664(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx728.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx2078, bmats.Axx425, bmats.Axx426, bmats.Axx486, bmats.Axx546, bmats.Axx600, bmats.Axx651, bmats.Axx693, bmats.Axx733, bmats.Axx751, bmats.Axx753, bmats.Axx759, bmats.Axx789, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx728, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
