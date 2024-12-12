#include "stdafx.h"
#include "fAxxeval5544.h"

inline int fAxxeval5544(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx805.data[0][0], 0, sizeof(bmats.Axx805.data[0][0])*BL*BL);
    int n_A_mats = 1;
    double_cmat A_mats[1] = {bmats.A_6_31, };
    double A_coeffs[1] = {16, };
    matlincomb_double_contiguous(bmats.Axx805, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
