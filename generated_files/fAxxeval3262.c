#include "stdafx.h"
#include "fAxxeval3262.h"

inline int fAxxeval3262(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2223.data[0][0], 0, sizeof(bmats.Axx2223.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_17_6, bmats.Axx2183, bmats.Axx2222, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2223, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
