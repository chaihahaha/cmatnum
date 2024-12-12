#include "stdafx.h"
#include "fAxxeval7040.h"

inline int fAxxeval7040(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx547.data[0][0], 0, sizeof(bmats.Axx547.data[0][0])*BL*BL);
    int n_A_mats = 6;
    double_cmat A_mats[6] = {bmats.Axx1233, bmats.Axx1237, bmats.Axx1567, bmats.Axx2545, bmats.Axx2849, bmats.Axx845, };
    double A_coeffs[6] = {1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx547, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
