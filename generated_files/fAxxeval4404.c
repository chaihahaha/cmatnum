#include "stdafx.h"
#include "fAxxeval4404.h"

inline int fAxxeval4404(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3220.data[0][0], 0, sizeof(bmats.Axx3220.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_31_9, bmats.Axx3174, bmats.Axx3219, };
    double A_coeffs[3] = {1, -1, 1, };
    matlincomb_double_contiguous(bmats.Axx3220, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
