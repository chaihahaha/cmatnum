#include "stdafx.h"
#include "fAxxeval6027.h"

inline int fAxxeval6027(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx418.data[0][0], 0, sizeof(bmats.Axx418.data[0][0])*BL*BL);
    int n_A_mats = 2;
    double_cmat A_mats[2] = {bmats.Axx2849, bmats.Axx550, };
    double A_coeffs[2] = {1, 1, };
    matlincomb_double_contiguous(bmats.Axx418, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
