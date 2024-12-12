#include "stdafx.h"
#include "fAxxeval6300.h"

inline int fAxxeval6300(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1617.data[0][0], 0, sizeof(bmats.Axx1617.data[0][0])*BL*BL);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx1026, bmats.Axx1027, bmats.Axx1028, bmats.Axx1029, bmats.Axx1030, bmats.Axx1031, bmats.Axx1032, bmats.Axx1033, bmats.Axx1034, bmats.Axx1035, bmats.Axx1905, bmats.Axx820, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1617, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
