#include "stdafx.h"
#include "fAxxeval3113.h"

inline int fAxxeval3113(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx899.data[0][0], 0, sizeof(bmats.Axx899.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx40, bmats.Axx41, bmats.Axx44, bmats.Axx45, bmats.Axx48, bmats.Axx49, bmats.Axx51, bmats.Axx52, bmats.Axx53, bmats.Axx55, bmats.Axx59, bmats.Axx61, bmats.Axx901, bmats.Axx951, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx899, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
