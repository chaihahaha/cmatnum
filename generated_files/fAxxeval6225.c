#include "stdafx.h"
#include "fAxxeval6225.h"

inline int fAxxeval6225(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx245.data[0][0], 0, sizeof(bmats.Axx245.data[0][0])*BL*BL);
    int n_A_mats = 15;
    double_cmat A_mats[15] = {bmats.Axx1925, bmats.Axx3165, bmats.Axx3168, bmats.Axx3169, bmats.Axx3172, bmats.Axx3173, bmats.Axx3176, bmats.Axx3180, bmats.Axx3181, bmats.Axx3183, bmats.Axx3185, bmats.Axx3188, bmats.Axx3189, bmats.Axx3192, bmats.Axx981, };
    double A_coeffs[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx245, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
