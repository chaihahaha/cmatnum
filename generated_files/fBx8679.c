#include "fBx8679.h"

inline int fBx8679(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 7;
    double_cmat B_mats[7] = {bmats.B_26_1, bmats.B_26_2, bmats.B_26_3, bmats.B_26_4, bmats.B_26_5, bmats.B_26_6, bmats.B_26_7, };
    double B_coeffs[7] = {1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Bx8679, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
