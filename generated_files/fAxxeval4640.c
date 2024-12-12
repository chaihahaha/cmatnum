#include "stdafx.h"
#include "fAxxeval4640.h"

inline int fAxxeval4640(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx3356.data[0][0], 0, sizeof(bmats.Axx3356.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx2222, bmats.Axx2286, bmats.Axx2355, bmats.Axx2424, bmats.Axx2492, bmats.Axx2555, bmats.Axx2623, bmats.Axx2700, bmats.Axx2767, bmats.Axx2831, bmats.Axx2913, bmats.Axx2997, bmats.Axx3074, bmats.Axx3142, bmats.Axx3210, bmats.Axx3354, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx3356, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
