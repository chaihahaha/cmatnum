#include "stdafx.h"
#include "fAxxeval2082.h"

inline int fAxxeval2082(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1815.data[0][0], 0, sizeof(bmats.Axx1815.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1814, bmats.Axx465, bmats.Axx466, bmats.Axx467, bmats.Axx468, bmats.Axx469, bmats.Axx470, bmats.Axx471, bmats.Axx472, bmats.Axx473, bmats.Axx474, bmats.Axx475, bmats.Axx476, bmats.Axx544, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1815, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
