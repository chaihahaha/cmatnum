#include "stdafx.h"
#include "fAxxeval3088.h"

inline int fAxxeval3088(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx735.data[0][0], 0, sizeof(bmats.Axx735.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx709, bmats.Axx900, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx735, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
