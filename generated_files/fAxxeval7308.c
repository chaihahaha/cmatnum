#include "stdafx.h"
#include "fAxxeval7308.h"

inline int fAxxeval7308(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx809.data[0][0], 0, sizeof(bmats.Axx809.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_19_18, bmats.Axx1284, bmats.Axx2401, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx809, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
