#include "stdafx.h"
#include "fBx7207.h"

inline int fBx7207(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 3;
    double_cmat B_mats[3] = {bmats.Bx7202, bmats.Bx7205, bmats.Bx7206, };
    double B_coeffs[3] = {1, 1, 1, };
memset(&bmats.Bx7207.data[0][0], 0, sizeof(bmats.Bx7207.data[0][0])*bmats.Bx7207.shape[0]*bmats.Bx7207.shape[1]);
    matlincomb_double_contiguous(bmats.Bx7207, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
