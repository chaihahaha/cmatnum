#include "stdafx.h"
#include "fAxxeval8218.h"

inline int fAxxeval8218(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1244.data[0][0], 0, sizeof(bmats.Axx1244.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1627, bmats.Axx1721, bmats.Axx2621, bmats.Axx2623, bmats.Axx284, bmats.Axx311, bmats.Axx3114, bmats.Axx542, bmats.Axx633, bmats.Axx69, bmats.Axx745, bmats.Axx784, bmats.Axx864, bmats.Axx866, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1244, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
