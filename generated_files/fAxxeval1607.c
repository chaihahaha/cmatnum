#include "stdafx.h"
#include "fAxxeval1607.h"

inline int fAxxeval1607(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1561.data[0][0], 0, sizeof(bmats.Axx1561.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx122, bmats.Axx123, bmats.Axx130, bmats.Axx131, bmats.Axx134, bmats.Axx135, bmats.Axx138, bmats.Axx139, bmats.Axx142, bmats.Axx143, bmats.Axx1541, bmats.Axx1559, bmats.Axx173, bmats.Axx174, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1561, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}