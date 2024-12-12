#include "stdafx.h"
#include "fAxxeval3032.h"

inline int fAxxeval3032(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx864.data[0][0], 0, sizeof(bmats.Axx864.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx158, bmats.Axx651, bmats.Axx802, };
    double A_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx864, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
