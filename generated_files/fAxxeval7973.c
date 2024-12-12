#include "stdafx.h"
#include "fAxxeval7973.h"

inline int fAxxeval7973(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx8.data[0][0], 0, sizeof(bmats.Axx8.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1456, bmats.Axx40, bmats.Axx768, };
    double A_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx8, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
