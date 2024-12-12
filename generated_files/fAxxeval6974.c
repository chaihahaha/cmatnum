#include "stdafx.h"
#include "fAxxeval6974.h"

inline int fAxxeval6974(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx160.data[0][0], 0, sizeof(bmats.Axx160.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1130, bmats.Axx1142, bmats.Axx1144, bmats.Axx1146, bmats.Axx1148, bmats.Axx1150, bmats.Axx1153, bmats.Axx1156, bmats.Axx2592, bmats.Axx337, bmats.Axx338, bmats.Axx922, bmats.Axx923, bmats.Axx987, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx160, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
