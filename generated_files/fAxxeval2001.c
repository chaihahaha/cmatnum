#include "stdafx.h"
#include "fAxxeval2001.h"

inline int fAxxeval2001(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1775.data[0][0], 0, sizeof(bmats.Axx1775.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx1756, bmats.Axx1763, bmats.Axx412, bmats.Axx413, bmats.Axx414, bmats.Axx415, bmats.Axx416, bmats.Axx417, bmats.Axx420, bmats.Axx421, bmats.Axx422, bmats.Axx439, bmats.Axx484, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1775, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
