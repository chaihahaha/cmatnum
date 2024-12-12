#include "stdafx.h"
#include "fAxxeval2785.h"

inline int fAxxeval2785(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx809.data[0][0], 0, sizeof(bmats.Axx809.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx2103, bmats.Axx2112, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx809, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
