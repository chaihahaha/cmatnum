#include "stdafx.h"
#include "fAxxeval6442.h"

inline int fAxxeval6442(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1818.data[0][0], 0, sizeof(bmats.Axx1818.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx15, bmats.Axx1559, bmats.Axx1576, bmats.Axx1590, bmats.Axx1596, bmats.Axx1751, bmats.Axx1916, bmats.Axx1961, bmats.Axx1996, bmats.Axx2094, bmats.Axx397, bmats.Axx528, bmats.Axx761, bmats.Axx873, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1818, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}