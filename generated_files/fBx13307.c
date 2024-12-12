#include "stdafx.h"
#include "fBx13307.h"

inline int fBx13307(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10352, bmats.Bx11048, bmats.Bx11612, bmats.Bx1185, bmats.Bx12066, bmats.Bx12487, bmats.Bx12754, bmats.Bx12949, bmats.Bx13305, bmats.Bx13306, bmats.Bx2888, bmats.Bx4598, bmats.Bx4637, bmats.Bx6283, bmats.Bx7433, bmats.Bx8517, bmats.Bx9472, };
    double B_coeffs[17] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
memset(&bmats.Bx13307.data[0][0], 0, sizeof(bmats.Bx13307.data[0][0])*bmats.Bx13307.shape[0]*bmats.Bx13307.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13307, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
