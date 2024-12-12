#include "stdafx.h"
#include "fAxxeval4461.h"

inline int fAxxeval4461(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3268.data[0][0], 0, sizeof(bmats.Axx3268.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx11, bmats.Axx12, bmats.Axx19, bmats.Axx20, bmats.Axx21, bmats.Axx23, bmats.Axx25, bmats.Axx27, bmats.Axx29, bmats.Axx31, bmats.Axx3266, bmats.Axx33, bmats.Axx35, bmats.Axx988, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3268, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
