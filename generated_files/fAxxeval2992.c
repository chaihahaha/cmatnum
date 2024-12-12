#include "stdafx.h"
#include "fAxxeval2992.h"

inline int fAxxeval2992(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx559.data[0][0], 0, sizeof(bmats.Axx559.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_11_7, bmats.Axx191, bmats.Axx784, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx559, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
