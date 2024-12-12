#include "stdafx.h"
#include "fAxxeval6147.h"

inline int fAxxeval6147(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2070.data[0][0], 0, sizeof(bmats.Axx2070.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1013, bmats.Axx1503, bmats.Axx1507, bmats.Axx1666, bmats.Axx1672, bmats.Axx1696, bmats.Axx2005, bmats.Axx2371, bmats.Axx2712, bmats.Axx3006, bmats.Axx3127, bmats.Axx3397, bmats.Axx3399, bmats.Axx377, bmats.Axx416, bmats.Axx550, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2070, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
