#include "stdafx.h"
#include "fAxxeval6130.h"

inline int fAxxeval6130(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx157.data[0][0], 0, sizeof(bmats.Axx157.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2089, bmats.Axx2239, bmats.Axx2241, bmats.Axx2243, bmats.Axx2244, bmats.Axx2247, bmats.Axx2248, bmats.Axx2251, bmats.Axx2252, bmats.Axx2255, bmats.Axx2256, bmats.Axx2263, bmats.Axx2264, bmats.Axx2270, bmats.Axx955, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx157, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
