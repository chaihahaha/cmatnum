#include "stdafx.h"
#include "fAxxeval3399.h"

inline int fAxxeval3399(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2344.data[0][0], 0, sizeof(bmats.Axx2344.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx2310, bmats.Axx2312, bmats.Axx2313, bmats.Axx2316, bmats.Axx2318, bmats.Axx2319, bmats.Axx2322, bmats.Axx2323, bmats.Axx2326, bmats.Axx2327, bmats.Axx2330, bmats.Axx2331, bmats.Axx2335, bmats.Axx2340, bmats.Axx957, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2344, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}