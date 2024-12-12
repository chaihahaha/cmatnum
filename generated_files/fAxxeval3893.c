#include "stdafx.h"
#include "fAxxeval3893.h"

inline int fAxxeval3893(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2774.data[0][0], 0, sizeof(bmats.Axx2774.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_24_9, bmats.Axx2735, bmats.Axx2773, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx2774, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
