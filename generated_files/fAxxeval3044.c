#include "stdafx.h"
#include "fAxxeval3044.h"

inline int fAxxeval3044(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx888.data[0][0], 0, sizeof(bmats.Axx888.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx227, bmats.Axx411, bmats.Axx481, bmats.Axx636, bmats.Axx679, bmats.Axx719, bmats.Axx761, bmats.Axx784, bmats.Axx801, bmats.Axx839, bmats.Axx846, bmats.Axx870, bmats.Axx890, bmats.Axx908, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx888, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
