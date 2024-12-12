#include "stdafx.h"
#include "fAxxeval3046.h"

inline int fAxxeval3046(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx406.data[0][0], 0, sizeof(bmats.Axx406.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx227, bmats.Axx411, bmats.Axx481, bmats.Axx527, bmats.Axx598, bmats.Axx636, bmats.Axx761, bmats.Axx784, bmats.Axx801, bmats.Axx839, bmats.Axx846, bmats.Axx870, bmats.Axx890, bmats.Axx908, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx406, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
