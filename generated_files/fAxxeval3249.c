#include "stdafx.h"
#include "fAxxeval3249.h"

inline int fAxxeval3249(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2212.data[0][0], 0, sizeof(bmats.Axx2212.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2165, bmats.Axx2182, bmats.Axx2185, bmats.Axx2186, bmats.Axx2189, bmats.Axx2190, bmats.Axx2193, bmats.Axx2194, bmats.Axx2198, bmats.Axx2202, bmats.Axx523, bmats.Axx87, bmats.Axx940, bmats.Axx943, bmats.Axx953, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2212, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}