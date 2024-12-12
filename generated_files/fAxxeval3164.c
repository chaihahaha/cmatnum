#include "stdafx.h"
#include "fAxxeval3164.h"

inline int fAxxeval3164(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx411.data[0][0], 0, sizeof(bmats.Axx411.data[0][0])*BL*BL);
    int n_A_mats = 11;
    double_cmat A_mats[11] = {bmats.Axx1685, bmats.Axx180, bmats.Axx1875, bmats.Axx298, bmats.Axx523, bmats.Axx569, bmats.Axx855, bmats.Axx901, bmats.Axx940, bmats.Axx943, bmats.Axx946, };
    double A_coeffs[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx411, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
