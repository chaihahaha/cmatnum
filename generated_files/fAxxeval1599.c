#include "stdafx.h"
#include "fAxxeval1599.h"

inline int fAxxeval1599(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1553.data[0][0], 0, sizeof(bmats.Axx1553.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx144, bmats.Axx145, bmats.Axx147, bmats.Axx148, bmats.Axx150, bmats.Axx151, bmats.Axx152, bmats.Axx153, bmats.Axx154, bmats.Axx1543, bmats.Axx1549, bmats.Axx155, bmats.Axx841, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1553, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}