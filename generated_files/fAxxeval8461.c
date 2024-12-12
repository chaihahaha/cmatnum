#include "stdafx.h"
#include "fAxxeval8461.h"

inline int fAxxeval8461(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1699.data[0][0], 0, sizeof(bmats.Axx1699.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1007, bmats.Axx1486, bmats.Axx1714, bmats.Axx2068, bmats.Axx2093, bmats.Axx2302, bmats.Axx287, bmats.Axx2871, bmats.Axx409, bmats.Axx461, bmats.Axx651, bmats.Axx815, bmats.Axx946, bmats.Axx962, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1699, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
