#include "stdafx.h"
#include "fAxxeval8433.h"

inline int fAxxeval8433(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2846.data[0][0], 0, sizeof(bmats.Axx2846.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1111, bmats.Axx1508, bmats.Axx1722, bmats.Axx2088, bmats.Axx2092, bmats.Axx2116, bmats.Axx2270, bmats.Axx2339, bmats.Axx2680, bmats.Axx279, bmats.Axx367, bmats.Axx431, bmats.Axx494, bmats.Axx513, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2846, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
