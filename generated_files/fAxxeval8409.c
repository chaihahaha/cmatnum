#include "stdafx.h"
#include "fAxxeval8409.h"

inline int fAxxeval8409(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2195.data[0][0], 0, sizeof(bmats.Axx2195.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1174, bmats.Axx1301, bmats.Axx1509, bmats.Axx1719, bmats.Axx199, bmats.Axx1992, bmats.Axx223, bmats.Axx224, bmats.Axx278, bmats.Axx2962, bmats.Axx572, bmats.Axx789, bmats.Axx790, bmats.Axx818, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2195, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
