#include "stdafx.h"
#include "fAxxeval2671.h"

inline int fAxxeval2671(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx546.data[0][0], 0, sizeof(bmats.Axx546.data[0][0])*BL*BL);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx2072, bmats.Axx2078, bmats.Axx762, bmats.Axx763, bmats.Axx766, bmats.Axx767, bmats.Axx768, bmats.Axx769, bmats.Axx770, bmats.Axx771, bmats.Axx772, bmats.Axx773, bmats.Axx774, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx546, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}