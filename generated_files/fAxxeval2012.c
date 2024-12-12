#include "stdafx.h"
#include "fAxxeval2012.h"

inline int fAxxeval2012(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx382.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx387, bmats.Axx388, bmats.Axx390, bmats.Axx391, bmats.Axx394, bmats.Axx395, bmats.Axx397, bmats.Axx398, bmats.Axx401, bmats.Axx402, bmats.Axx405, bmats.Axx406, bmats.Axx421, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx382, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
