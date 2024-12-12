#include "stdafx.h"
#include "fAxxeval4651.h"

inline int fAxxeval4651(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3365.data[0][0], 0, sizeof(bmats.Axx3365.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2230, bmats.Axx2298, bmats.Axx2365, bmats.Axx2433, bmats.Axx2501, bmats.Axx2563, bmats.Axx2633, bmats.Axx2706, bmats.Axx2777, bmats.Axx2848, bmats.Axx2923, bmats.Axx3002, bmats.Axx3080, bmats.Axx3157, bmats.Axx3229, bmats.Axx3363, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3365, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
