#include "stdafx.h"
#include "fAxxeval1612.h"

inline int fAxxeval1612(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    cblas_dscal(BL*BL, 1, &bmats.Axx1541.data[0][0], 1);
    int n_A_mats = 13;
    double_cmat A_mats[13] = {bmats.Axx122, bmats.Axx123, bmats.Axx126, bmats.Axx127, bmats.Axx130, bmats.Axx131, bmats.Axx134, bmats.Axx135, bmats.Axx138, bmats.Axx139, bmats.Axx142, bmats.Axx143, bmats.Axx1559, };
    double A_coeffs[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1541, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
