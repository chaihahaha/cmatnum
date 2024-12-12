#include "stdafx.h"
#include "fAxxeval7831.h"

inline int fAxxeval7831(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2310.data[0][0], 0, sizeof(bmats.Axx2310.data[0][0])*BL*BL);
    int n_A_mats = 3;
    double_cmat A_mats[3] = {bmats.A_24_20, bmats.Axx120, bmats.Axx1291, };
    double A_coeffs[3] = {1, 1, -1, };
    matlincomb_double_contiguous(bmats.Axx2310, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
