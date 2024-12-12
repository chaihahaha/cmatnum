#include "stdafx.h"
#include "fAxxeval4617.h"

inline int fAxxeval4617(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3336.data[0][0], 0, sizeof(bmats.Axx3336.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2226, bmats.Axx2293, bmats.Axx2360, bmats.Axx2428, bmats.Axx2496, bmats.Axx2558, bmats.Axx2628, bmats.Axx2702, bmats.Axx2773, bmats.Axx2843, bmats.Axx2914, bmats.Axx2998, bmats.Axx3076, bmats.Axx3152, bmats.Axx3219, bmats.Axx3330, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3336, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
