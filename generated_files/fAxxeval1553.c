#include "stdafx.h"
#include "fAxxeval1553.h"

inline int fAxxeval1553(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1535.data[0][0], 0, sizeof(bmats.Axx1535.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1490, bmats.Axx1533, bmats.Axx66, bmats.Axx67, bmats.Axx82, bmats.Axx83, bmats.Axx86, bmats.Axx87, bmats.Axx90, bmats.Axx91, bmats.Axx94, bmats.Axx95, bmats.Axx98, bmats.Axx99, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1535, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
