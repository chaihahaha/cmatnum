#include "stdafx.h"
#include "fAxxeval7106.h"

inline int fAxxeval7106(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx2049.data[0][0], 0, sizeof(bmats.Axx2049.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1132, bmats.Axx1195, bmats.Axx1208, bmats.Axx1210, bmats.Axx1212, bmats.Axx1215, bmats.Axx1220, bmats.Axx1223, bmats.Axx1226, bmats.Axx1229, bmats.Axx2126, bmats.Axx576, bmats.Axx919, bmats.Axx920, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx2049, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
