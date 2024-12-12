#include "stdafx.h"
#include "fAxxeval1596.h"

inline int fAxxeval1596(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1550.data[0][0], 0, sizeof(bmats.Axx1550.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx144, bmats.Axx145, bmats.Axx146, bmats.Axx147, bmats.Axx148, bmats.Axx149, bmats.Axx150, bmats.Axx151, bmats.Axx152, bmats.Axx153, bmats.Axx154, bmats.Axx1549, bmats.Axx155, bmats.Axx841, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1550, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
