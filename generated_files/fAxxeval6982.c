#include "stdafx.h"
#include "fAxxeval6982.h"

inline int fAxxeval6982(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx124.data[0][0], 0, sizeof(bmats.Axx124.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.Axx1173, bmats.Axx1174, bmats.Axx1829, };
    double A_coeffs[3] = {1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx124, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
