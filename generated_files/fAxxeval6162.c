#include "stdafx.h"
#include "fAxxeval6162.h"

inline int fAxxeval6162(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1995.data[0][0], 0, sizeof(bmats.Axx1995.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx1015, bmats.Axx1556, bmats.Axx1634, bmats.Axx1640, bmats.Axx1665, bmats.Axx1854, bmats.Axx1953, bmats.Axx2114, bmats.Axx2436, bmats.Axx2783, bmats.Axx2855, bmats.Axx3240, bmats.Axx3391, bmats.Axx3404, bmats.Axx474, bmats.Axx80, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1995, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
