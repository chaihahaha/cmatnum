#include "stdafx.h"
#include "fAxxeval2471.h"

inline int fAxxeval2471(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2003.data[0][0], 0, sizeof(bmats.Axx2003.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx2002, bmats.Axx680, bmats.Axx681, bmats.Axx682, bmats.Axx683, bmats.Axx684, bmats.Axx685, bmats.Axx686, bmats.Axx687, bmats.Axx688, bmats.Axx689, bmats.Axx690, bmats.Axx691, bmats.Axx735, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2003, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}