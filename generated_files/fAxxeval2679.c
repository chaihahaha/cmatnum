#include "stdafx.h"
#include "fAxxeval2679.h"

inline int fAxxeval2679(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx774.data[0][0], 1);
    int n_A_mats = 12;
    double_cmat A_mats[12] = {bmats.Axx2072, bmats.Axx2078, bmats.Axx762, bmats.Axx763, bmats.Axx764, bmats.Axx765, bmats.Axx766, bmats.Axx767, bmats.Axx768, bmats.Axx769, bmats.Axx772, bmats.Axx773, };
    double A_coeffs[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx774, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
