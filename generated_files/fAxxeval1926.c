#include "stdafx.h"
#include "fAxxeval1926.h"

inline int fAxxeval1926(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1734.data[0][0], 0, sizeof(bmats.Axx1734.data[0][0])*BL*BL);
    int n_A_mats = 7;
    double_cmat A_mats[7] = {bmats.Axx1684, bmats.Axx1730, bmats.Axx1732, bmats.Axx297, bmats.Axx375, bmats.Axx378, bmats.Axx381, };
    double A_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1734, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
