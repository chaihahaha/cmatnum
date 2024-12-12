#include "stdafx.h"
#include "fAxxeval4863.h"

inline int fAxxeval4863(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx155.data[0][0], 0, sizeof(bmats.Axx155.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx1824, bmats.Axx904, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx155, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
