#include "stdafx.h"
#include "fAxxeval2601.h"

inline int fAxxeval2601(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx459.data[0][0], 0, sizeof(bmats.Axx459.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_8_7, bmats.Axx2042, bmats.Axx2060, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx459, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
