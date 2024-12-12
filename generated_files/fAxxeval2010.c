#include "stdafx.h"
#include "fAxxeval2010.h"

inline int fAxxeval2010(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1779.data[0][0], 0, sizeof(bmats.Axx1779.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx382, bmats.Axx387, bmats.Axx388, bmats.Axx390, bmats.Axx391, bmats.Axx394, bmats.Axx395, bmats.Axx397, bmats.Axx398, bmats.Axx405, bmats.Axx406, bmats.Axx421, bmats.Axx440, bmats.Axx441, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1779, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
