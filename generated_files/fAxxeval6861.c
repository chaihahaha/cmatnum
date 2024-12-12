#include "stdafx.h"
#include "fAxxeval6861.h"

inline int fAxxeval6861(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2847.data[0][0], 0, sizeof(bmats.Axx2847.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1070, bmats.Axx1071, bmats.Axx1097, bmats.Axx1099, bmats.Axx1101, bmats.Axx1103, bmats.Axx1105, bmats.Axx1107, bmats.Axx1109, bmats.Axx1112, bmats.Axx334, bmats.Axx335, bmats.Axx554, bmats.Axx780, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2847, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
