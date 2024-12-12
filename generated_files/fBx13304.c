#include "stdafx.h"
#include "fBx13304.h"

inline int fBx13304(pack_mats_32x32 bmats) {
    int BL = bmats.B_1_1.shape[0];
    int n_B_mats = 17;
    double_cmat B_mats[17] = {bmats.Bx10358, bmats.Bx11054, bmats.Bx11619, bmats.Bx12051, bmats.Bx1232, bmats.Bx12492, bmats.Bx12759, bmats.Bx12952, bmats.Bx13302, bmats.Bx13303, bmats.Bx2917, bmats.Bx4543, bmats.Bx4643, bmats.Bx6291, bmats.Bx7439, bmats.Bx8522, bmats.Bx9454, };
    double B_coeffs[17] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
memset(&bmats.Bx13304.data[0][0], 0, sizeof(bmats.Bx13304.data[0][0])*bmats.Bx13304.shape[0]*bmats.Bx13304.shape[1]);
    matlincomb_double_contiguous(bmats.Bx13304, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);

    return 0;
}
