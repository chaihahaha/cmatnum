#include "stdafx.h"
#include "fAxxeval2096.h"

inline int fAxxeval2096(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx476.data[0][0], 0, sizeof(bmats.Axx476.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1795, bmats.Axx445, bmats.Axx446, bmats.Axx452, bmats.Axx453, bmats.Axx455, bmats.Axx456, bmats.Axx459, bmats.Axx460, bmats.Axx463, bmats.Axx464, bmats.Axx466, bmats.Axx501, bmats.Axx502, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx476, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}