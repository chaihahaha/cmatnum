#include "stdafx.h"
#include "fAxxeval6416.h"

inline int fAxxeval6416(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    memset(&bmats.Axx1489.data[0][0], 0, sizeof(bmats.Axx1489.data[0][0])*BL*BL);
    int n_A_mats = 14;
    double_cmat A_mats[14] = {bmats.Axx1547, bmats.Axx1564, bmats.Axx1806, bmats.Axx1900, bmats.Axx1981, bmats.Axx2024, bmats.Axx208, bmats.Axx23, bmats.Axx463, bmats.Axx505, bmats.Axx691, bmats.Axx770, bmats.Axx781, bmats.Axx842, };
    double A_coeffs[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };
    matlincomb_double_contiguous(bmats.Axx1489, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);

    return 0;
}