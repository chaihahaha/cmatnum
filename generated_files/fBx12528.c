#include "stdafx.h"
#include "fBx12528.h"

inline int fBx12528(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 5;
    double_cmat B_mats[5] = {bmats.B_4_15, bmats.B_4_5, bmats.Bx10462, bmats.Bx11819, bmats.Bx4054, };
    double B_coeffs[5] = {1, 1, 1, 1, 1, };
memset(&bmats.Bx12528.data[0][0], 0, sizeof(bmats.Bx12528.data[0][0])*bmats.Bx12528.shape[0]*bmats.Bx12528.shape[1]);
    matlincomb_double_contiguous(bmats.Bx12528, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
