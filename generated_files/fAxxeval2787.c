#include "stdafx.h"
#include "fAxxeval2787.h"

inline int fAxxeval2787(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx806.data[0][0], 0, sizeof(bmats.Axx806.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx559, bmats.Axx560, bmats.Axx741, bmats.Axx742, bmats.Axx770, bmats.Axx783, bmats.Axx784, bmats.Axx792, bmats.Axx793, bmats.Axx795, bmats.Axx796, bmats.Axx813, bmats.Axx824, bmats.Axx825, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx806, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}