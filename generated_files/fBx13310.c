#include "stdafx.h"
#include "fBx13310.h"

inline int fBx13310(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 19;
    double_cmat B_mats[19] = {bmats.Bx10241, bmats.Bx11064, bmats.Bx11634, bmats.Bx12080, bmats.Bx12405, bmats.Bx12766, bmats.Bx12964, bmats.Bx13308, bmats.Bx13309, bmats.Bx2503, bmats.Bx2530, bmats.Bx3035, bmats.Bx3109, bmats.Bx4634, bmats.Bx5971, bmats.Bx647, bmats.Bx7449, bmats.Bx8534, bmats.Bx9483, };
    double B_coeffs[19] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13310.data[0][0], 0, sizeof(bmats.Bx13310.data[0][0])*bmats.Bx13310.shape[0]*bmats.Bx13310.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13310, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
