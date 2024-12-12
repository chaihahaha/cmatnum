#include "stdafx.h"
#include "fAxxeval6170.h"

inline int fAxxeval6170(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1761.data[0][0], 0, sizeof(bmats.Axx1761.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx144, bmats.Axx1695, bmats.Axx1733, bmats.Axx1811, bmats.Axx2017, bmats.Axx2067, bmats.Axx2085, bmats.Axx2131, bmats.Axx2713, bmats.Axx2782, bmats.Axx3015, bmats.Axx3198, bmats.Axx419, bmats.Axx439, bmats.Axx588, bmats.Axx679, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1761, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
