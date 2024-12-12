#include "stdafx.h"
#include "fAxxeval4328.h"

inline int fAxxeval4328(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3157.data[0][0], 0, sizeof(bmats.Axx3157.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_27_11, bmats.Axx3115, bmats.Axx3156, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3157, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
