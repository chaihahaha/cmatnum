#include "stdafx.h"
#include "fAxxeval6666.h"

inline int fAxxeval6666(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1585.data[0][0], 0, sizeof(bmats.Axx1585.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1046, bmats.Axx1047, bmats.Axx1050, bmats.Axx1051, bmats.Axx1058, bmats.Axx1059, bmats.Axx1062, bmats.Axx1063, bmats.Axx364, bmats.Axx365, bmats.Axx424, bmats.Axx697, bmats.Axx935, bmats.Axx936, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1585, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
