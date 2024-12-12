#include "stdafx.h"
#include "fAxxeval2960.h"

inline int fAxxeval2960(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx431.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx191, bmats.Axx219, bmats.Axx495, bmats.Axx555, bmats.Axx560, bmats.Axx608, bmats.Axx654, bmats.Axx698, bmats.Axx737, bmats.Axx779, bmats.Axx817, bmats.Axx868, bmats.Axx887, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx431, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
