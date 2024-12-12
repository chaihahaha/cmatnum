#include "stdafx.h"
#include "fAxxeval6649.h"

inline int fAxxeval6649(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx466.data[0][0], 0, sizeof(bmats.Axx466.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_27_32, bmats.Axx206, bmats.Axx2160, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx466, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
