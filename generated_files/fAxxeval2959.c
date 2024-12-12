#include "stdafx.h"
#include "fAxxeval2959.h"

inline int fAxxeval2959(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx139.data[0][0], 0, sizeof(bmats.Axx139.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx191, bmats.Axx219, bmats.Axx431, bmats.Axx495, bmats.Axx555, bmats.Axx560, bmats.Axx608, bmats.Axx654, bmats.Axx698, bmats.Axx737, bmats.Axx779, bmats.Axx855, bmats.Axx866, bmats.Axx887, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx139, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
