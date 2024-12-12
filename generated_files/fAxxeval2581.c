#include "stdafx.h"
#include "fAxxeval2581.h"

inline int fAxxeval2581(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx730.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx2034, bmats.Axx2046, bmats.Axx720, bmats.Axx721, bmats.Axx722, bmats.Axx723, bmats.Axx724, bmats.Axx725, bmats.Axx726, bmats.Axx727, bmats.Axx731, bmats.Axx777, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx730, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
