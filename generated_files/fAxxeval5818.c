#include "stdafx.h"
#include "fAxxeval5818.h"

inline int fAxxeval5818(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx57.data[0][0], 0, sizeof(bmats.Axx57.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1011, bmats.Axx1016, bmats.Axx153, bmats.Axx1656, bmats.Axx1677, bmats.Axx1696, bmats.Axx1729, bmats.Axx209, bmats.Axx211, bmats.Axx2167, bmats.Axx2412, bmats.Axx2858, bmats.Axx3365, bmats.Axx372, bmats.Axx644, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx57, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
