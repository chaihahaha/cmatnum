#include "stdafx.h"
#include "fm_826.h"

inline int fm_826(double_cmat m, pack_mats_32x32 bmats) {
    double dnum17 = 1/17.0;
    int BL = bmats.A_1_1.shape[0];
    double_cmat tmp0, tmp1;
    create_double_matrix(pairint {BL, BL}, &tmp0);
    create_double_matrix(pairint {BL, BL}, &tmp1);
    int n_A_mats = 4;
    double_cmat A_mats[4] = {bmats.Axx1369, bmats.Axx1381, bmats.Axx297, bmats.Axx755, };
    double A_coeffs[4] = {1, -1, 1, 1, };
    int n_B_mats = 14;
    double_cmat B_mats[14] = {bmats.B_17_26, bmats.B_25_26, bmats.Bx110, bmats.Bx111, bmats.Bx112, bmats.Bx113, bmats.Bx114, bmats.Bx115, bmats.Bx116, bmats.Bx7241, bmats.Bx7590, bmats.Bx7591, bmats.Bx7592, bmats.Bx7593, };
    double B_coeffs[14] = {-1, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, };
    matlincomb_double_contiguous(tmp0, n_A_mats, (double_cmat*)A_mats, (double*)A_coeffs);
    matlincomb_double_contiguous(tmp1, n_B_mats, (double_cmat*)B_mats, (double*)B_coeffs);
    cblas_dscal(BL*BL, dnum17, &tmp0.data[0][0], 1);
    matmul_double_blas(m, tmp0, tmp1);
    cblas_daxpy(BL*BL, 1, &m.data[0][0], 1, &bmats.C_25_26.data[0][0], 1);
    free_double_matrix(tmp0);
    free_double_matrix(tmp1);
    return 0;
}
