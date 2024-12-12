#include "stdafx.h"
#include "fAxxeval3186.h"

inline int fAxxeval3186(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2178.data[0][0], 0, sizeof(bmats.Axx2178.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1685, bmats.Axx180, bmats.Axx1875, bmats.Axx2165, bmats.Axx298, bmats.Axx523, bmats.Axx569, bmats.Axx855, bmats.Axx901, bmats.Axx908, bmats.Axx943, bmats.Axx946, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2178, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
