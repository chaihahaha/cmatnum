#include "stdafx.h"
#include "fAxxeval4464.h"

inline int fAxxeval4464(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx19.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx11, bmats.Axx12, bmats.Axx15, bmats.Axx16, bmats.Axx20, bmats.Axx21, bmats.Axx23, bmats.Axx25, bmats.Axx31, bmats.Axx3266, bmats.Axx33, bmats.Axx35, bmats.Axx988, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx19, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
