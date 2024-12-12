#include "stdafx.h"
#include "fAxxeval4856.h"

inline int fAxxeval4856(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1726.data[0][0], 0, sizeof(bmats.Axx1726.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1549, bmats.Axx1904, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx1726, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
