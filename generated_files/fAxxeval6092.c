#include "stdafx.h"
#include "fAxxeval6092.h"

inline int fAxxeval6092(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1501.data[0][0], 0, sizeof(bmats.Axx1501.data[0][0])*BL*BL);
    int n_A_mats = 16;
    double_cmat A_mats[16] = {bmats.Axx131, bmats.Axx1498, bmats.Axx1736, bmats.Axx1758, bmats.Axx1762, bmats.Axx1868, bmats.Axx1940, bmats.Axx2109, bmats.Axx2479, bmats.Axx2599, bmats.Axx3388, bmats.Axx3407, bmats.Axx382, bmats.Axx639, bmats.Axx667, bmats.Axx883, };
    double A_coeffs[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1501, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}
