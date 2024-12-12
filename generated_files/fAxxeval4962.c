#include "stdafx.h"
#include "fAxxeval4962.h"

inline int fAxxeval4962(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3387.data[0][0], 0, sizeof(bmats.Axx3387.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_4_28, bmats.Axx1726, bmats.Axx3391, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx3387, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
