#include "stdafx.h"
#include "fAxxeval2495.h"

inline int fAxxeval2495(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1949.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx549, bmats.Axx550, bmats.Axx663, bmats.Axx664, bmats.Axx666, bmats.Axx667, bmats.Axx669, bmats.Axx670, bmats.Axx676, bmats.Axx677, bmats.Axx683, bmats.Axx704, bmats.Axx705, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1949, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
