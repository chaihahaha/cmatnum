#include "stdafx.h"
#include "fBx13241.h"

inline int fBx13241(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10664, bmats.Bx11508, bmats.Bx11934, bmats.Bx12299, bmats.Bx12709, bmats.Bx12898, bmats.Bx13236, bmats.Bx13237, bmats.Bx13240, bmats.Bx2637, bmats.Bx267, bmats.Bx4284, bmats.Bx5636, bmats.Bx6883, bmats.Bx8379, bmats.Bx9260, bmats.Bx9986, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13241.data[0][0], 0, sizeof(bmats.Bx13241.data[0][0])*bmats.Bx13241.shape[0]*bmats.Bx13241.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13241, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
