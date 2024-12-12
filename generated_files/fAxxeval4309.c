#include "stdafx.h"
#include "fAxxeval4309.h"

inline int fAxxeval4309(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3142.data[0][0], 0, sizeof(bmats.Axx3142.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_27_5, bmats.Axx3100, bmats.Axx3141, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3142, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
