#include "stdafx.h"
#include "fAxxeval581.h"

inline int fAxxeval581(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx582.data[0][0], 0, sizeof(bmats.Axx582.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_3_11, };
    double A_coeffs[1] = {17, };
    matlincomb_double_contiguous(bmats.Axx582, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
