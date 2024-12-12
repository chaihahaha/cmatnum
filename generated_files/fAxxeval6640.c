#include "stdafx.h"
#include "fAxxeval6640.h"

inline int fAxxeval6640(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx857.data[0][0], 0, sizeof(bmats.Axx857.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_27_29, bmats.Axx2682, bmats.Axx2684, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx857, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
