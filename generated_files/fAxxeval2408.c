#include "stdafx.h"
#include "fAxxeval2408.h"

inline int fAxxeval2408(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx621.data[0][0], 0, sizeof(bmats.Axx621.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_10_2, bmats.Axx1939, bmats.Axx647, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx621, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
