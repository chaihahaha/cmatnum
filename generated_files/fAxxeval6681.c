#include "stdafx.h"
#include "fAxxeval6681.h"

inline int fAxxeval6681(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx486.data[0][0], 0, sizeof(bmats.Axx486.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_27_21, bmats.Axx3124, bmats.Axx410, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx486, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
