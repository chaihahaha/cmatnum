#include "stdafx.h"
#include "fAxxeval2553.h"

inline int fAxxeval2553(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2037.data[0][0], 0, sizeof(bmats.Axx2037.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx2034, bmats.Axx720, bmats.Axx721, bmats.Axx722, bmats.Axx723, bmats.Axx724, bmats.Axx725, bmats.Axx726, bmats.Axx727, bmats.Axx728, bmats.Axx729, bmats.Axx777, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2037, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}