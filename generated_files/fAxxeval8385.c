#include "stdafx.h"
#include "fAxxeval8385.h"

inline int fAxxeval8385(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3142.data[0][0], 0, sizeof(bmats.Axx3142.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx119, bmats.Axx1621, bmats.Axx1808, bmats.Axx1915, bmats.Axx2138, bmats.Axx2322, bmats.Axx3110, bmats.Axx3271, bmats.Axx371, bmats.Axx384, bmats.Axx689, bmats.Axx720, bmats.Axx813, bmats.Axx949, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3142, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
